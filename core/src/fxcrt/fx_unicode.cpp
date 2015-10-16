// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "../../include/fxcrt/fx_ucd.h"

FX_DWORD FX_GetUnicodeProperties(FX_WCHAR wch) {
  return kTextLayoutCodeProperties[(FX_WORD)wch];
}
FX_BOOL FX_IsCtrlCode(FX_WCHAR ch) {
  FX_DWORD dwRet =
      (kTextLayoutCodeProperties[(FX_WORD)ch] & FX_CHARTYPEBITSMASK);
  return dwRet == FX_CHARTYPE_Tab || dwRet == FX_CHARTYPE_Control;
}
FX_BOOL FX_IsRotationCode(FX_WCHAR ch) {
  return (kTextLayoutCodeProperties[(FX_WORD)ch] & 0x8000) != 0;
}
FX_BOOL FX_IsCombinationChar(FX_WCHAR wch) {
  FX_DWORD dwProps =
      (kTextLayoutCodeProperties[(FX_WORD)wch] & FX_CHARTYPEBITSMASK);
  return dwProps == FX_CHARTYPE_Combination;
}
FX_BOOL FX_IsBidiChar(FX_WCHAR wch) {
  FX_DWORD dwProps = kTextLayoutCodeProperties[(FX_WORD)wch];
  int32_t iBidiCls = (dwProps & FX_BIDICLASSBITSMASK) >> FX_BIDICLASSBITS;
  return (FX_BIDICLASS_R == iBidiCls || FX_BIDICLASS_AL == iBidiCls);
}
FX_WCHAR FX_GetMirrorChar(FX_WCHAR wch, FX_BOOL bRTL, FX_BOOL bVertical) {
  FX_DWORD dwProps = kTextLayoutCodeProperties[(FX_WORD)wch];
  FX_DWORD dwTemp = (dwProps & 0xFF800000);
  if (bRTL && dwTemp < 0xFF800000) {
    wch = kFXTextLayoutBidiMirror[dwTemp >> 23];
    dwProps = kTextLayoutCodeProperties[(FX_WORD)wch];
  }
  if (bVertical) {
    dwTemp = (dwProps & 0x007E0000);
    if (dwTemp < 0x007E0000) {
      wch = kFXTextLayoutVerticalMirror[dwTemp >> 17];
    }
  }
  return wch;
}
FX_WCHAR FX_GetMirrorChar(FX_WCHAR wch,
                          FX_DWORD dwProps,
                          FX_BOOL bRTL,
                          FX_BOOL bVertical) {
  FX_DWORD dwTemp = (dwProps & 0xFF800000);
  if (bRTL && dwTemp < 0xFF800000) {
    wch = kFXTextLayoutBidiMirror[dwTemp >> 23];
    dwProps = kTextLayoutCodeProperties[(FX_WORD)wch];
  }
  if (bVertical) {
    dwTemp = (dwProps & 0x007E0000);
    if (dwTemp < 0x007E0000) {
      wch = kFXTextLayoutVerticalMirror[dwTemp >> 17];
    }
  }
  return wch;
}
