// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "../fgas_base.h"

extern const FX_LINEBREAKTYPE gs_FX_LineBreak_PairTable[64][32] = {
    {FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBPB, FX_LBPB, FX_LBPB, FX_LBCP, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBPB, FX_LBPB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBPB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBPB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBIB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBIB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBIB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBIB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBIB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBDB, FX_LBPB, FX_LBPB, FX_LBPB, FX_LBDB, FX_LBPB,
     FX_LBDB, FX_LBIB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBPB, FX_LBPB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBPB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBDB, FX_LBPB, FX_LBIB, FX_LBDB, FX_LBIB, FX_LBPB, FX_LBPB, FX_LBPB,
     FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBDB, FX_LBIB, FX_LBIB,
     FX_LBDB, FX_LBDB, FX_LBPB, FX_LBCB, FX_LBPB, FX_LBDB, FX_LBDB, FX_LBDB,
     FX_LBDB, FX_LBDB, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
    {FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN,
     FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN, FX_LBUN},
};
void FX_GetLineBreakPositions(const FX_WCHAR* pwsText,
                              FX_LINEBREAKTYPE* pBrkType,
                              int32_t iLength) {
  if (iLength < 2) {
    return;
  }
  FX_DWORD dwCur, dwNext;
  FX_WCHAR wch;
  wch = *pwsText++;
  dwCur = kTextLayoutCodeProperties[(FX_WORD)wch] & 0x003F;
  iLength--;
  for (int32_t i = 0; i < iLength; i++) {
    wch = *pwsText++;
    dwNext = kTextLayoutCodeProperties[(FX_WORD)wch] & 0x003F;
    if (dwNext == FX_CBP_SP) {
      pBrkType[i] = FX_LBT_PROHIBITED_BRK;
    } else {
      pBrkType[i] = *((const FX_LINEBREAKTYPE*)gs_FX_LineBreak_PairTable +
                      (dwCur << 5) + dwNext);
    }
    dwCur = dwNext;
  }
  pBrkType[iLength] = FX_LBT_INDIRECT_BRK;
}
void FX_GetLineBreakPositions(const FX_WCHAR* pwsText,
                              int32_t iLength,
                              CFX_Int32MassArray& bp) {
  if (iLength < 2) {
    return;
  }
  FX_LINEBREAKTYPE eType;
  FX_DWORD dwCur, dwNext;
  FX_WCHAR wch;
  wch = *pwsText++;
  dwCur = kTextLayoutCodeProperties[(FX_WORD)wch] & 0x003F;
  iLength--;
  for (int32_t i = 0; i < iLength; i++) {
    wch = *pwsText++;
    dwNext = kTextLayoutCodeProperties[(FX_WORD)wch] & 0x003F;
    if (dwNext == FX_CBP_SP) {
      eType = FX_LBT_PROHIBITED_BRK;
    } else {
      eType = *((const FX_LINEBREAKTYPE*)gs_FX_LineBreak_PairTable +
                (dwCur << 5) + dwNext);
    }
    if (eType == FX_LBT_DIRECT_BRK) {
      bp.Add(i);
    }
    dwCur = dwNext;
  }
}
