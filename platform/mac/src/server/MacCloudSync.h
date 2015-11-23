/* -*- ObjC -*-

 MacOS X implementation of the SKK input method.

 Copyright (C) 2015 mzp <mzpppp@gmail.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
 */

#ifndef MacCloudSync_h
#define MacCloudSync_h

#import <CloudKit/CloudKit.h>
#include <map>
#include <string>
#include "SKKCloudSync.h"

class MacCloudSync : public SKKCloudSync {
    CKDatabase* database_;
    SKKDictionaryFile* dictionaryFile_;

    void fetch(CKQuery* query, void (^f)(const std::map<std::string, CKRecord*>& records));
    void create(NSString* entry, NSString* candidates, bool okuri);
    void update(CKRecord* record, NSString* candidates, bool okuri);
    void save(bool okuri, SKKDictionaryEntryContainer& container);

    CKQuery* buildQuery(bool okuri, SKKDictionaryEntryIterator from, SKKDictionaryEntryIterator to);

public:
    virtual void Initialize(SKKDictionaryFile& dictionaryFile);
    virtual void Save();
};

#endif
