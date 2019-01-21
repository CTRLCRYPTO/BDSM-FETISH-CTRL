// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2012-2015 The PPCoin developers
// Copyright (c) 2013-2017 The Novacoin
// Copyright (c) 2014-2015 The BDSM COIN(BDSM) & Fetish Coin(FETISH) developers
// Copyright (c) 2014-2017 The BDSM-FETISH(WHIPPED) developers
// Copyright (c) 2018 The BDSM-FETISH(CTRL) developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROL_H
#define COINCONTROL_H

/** Coin Control Features. */
class CCoinControl
{
public:
    CTxDestination destChange;

    CCoinControl()
    {
        SetNull();
    }
        
    void SetNull()
    {
        destChange = CNoDestination();
        setSelected.clear();
    }
    
    bool HasSelected() const
    {
        return (setSelected.size() > 0);
    }
    
    bool IsSelected(const uint256& hash, unsigned int n) const
    {
        COutPoint outpt(hash, n);
        return (setSelected.count(outpt) > 0);
    }
    
    void Select(COutPoint& output)
    {
        setSelected.insert(output);
    }
    
    void UnSelect(COutPoint& output)
    {
        setSelected.erase(output);
    }
    
    void UnSelectAll()
    {
        setSelected.clear();
    }

    void ListSelected(std::vector<COutPoint>& vOutpoints)
    {
        vOutpoints.assign(setSelected.begin(), setSelected.end());
    }
        
private:
    std::set<COutPoint> setSelected;

};

#endif // COINCONTROL_H
