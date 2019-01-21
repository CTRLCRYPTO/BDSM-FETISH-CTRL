// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2012-2015 The PPCoin developers
// Copyright (c) 2013-2017 The Novacoin
// Copyright (c) 2014-2015 The BDSM COIN(BDSM) & Fetish Coin(FETISH) developers
// Copyright (c) 2014-2017 The BDSM-FETISH(WHIPPED) developers
// Copyright (c) 2018 The BDSM-FETISH(CTRL) developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QTest>
#include <QObject>

#include "uritests.h"

// This is all you need to run all the tests
int main(int argc, char *argv[])
{
    bool fInvalid = false;

    URITests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;

    return fInvalid;
}
