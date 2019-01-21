# Copyright (c) 2009-2010 Satoshi Nakamoto
# Copyright (c) 2009-2014 The Bitcoin developers
# Copyright (c) 2012-2014 The Novacoin developers
# Copyright (c) 2014-2015 The BDSM COIN(BDSM) & Fetish Coin(FETISH) developers
# Copyright (c) 2014-2017 The BDSM-FETISH(WHIPPED) developers
# Copyright (c) 2018 The BDSM-FETISH(CTRL) developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

#!/bin/sh

if [ $# -gt 0 ]; then
    FILE="$1"
    shift
    if [ -f "$FILE" ]; then
        INFO="$(head -n 1 "$FILE")"
    fi
else
    echo "Usage: $0 <filename>"
    exit 1
fi

if [ -e "$(which git)" ]; then
    # clean 'dirty' status of touched files that haven't been modified
    git diff >/dev/null 2>/dev/null 

    # get a string like "v0.6.0-66-g59887e8-dirty"
    DESC="$(git describe --dirty 2>/dev/null)"

    # get a string like "2012-04-10 16:27:19 +0200"
    TIME="$(git log -n 1 --format="%ci")"
fi

if [ -n "$DESC" ]; then
    NEWINFO="#define BUILD_DESC \"$DESC\""
else
    NEWINFO="// No build information available"
fi

# only update build.h if necessary
if [ "$INFO" != "$NEWINFO" ]; then
    echo "$NEWINFO" >"$FILE"
    echo "#define BUILD_DATE \"$TIME\"" >>"$FILE"
fi
