// Copyright (c) 2011-2016, Pacific Biosciences of California, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the
// disclaimer below) provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//  * Neither the name of Pacific Biosciences nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY PACIFIC
// BIOSCIENCES AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PACIFIC BIOSCIENCES OR ITS
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#include <stdexcept>
#include <utility>

#include <pacbio/exception/StateError.h>
#include <pacbio/consensus/ModelConfig.h>

#include "ModelFactory.h"

namespace PacBio {
namespace Consensus {

using ChemistryNotFound = PacBio::Exception::ChemistryNotFound;

ModelCreator::ModelCreator(const std::set<std::string>& names)
{
    for (const std::string& name : names)
        if (!ModelFactory::Register(name, this))
            throw std::runtime_error("duplicate model inserted into factory!");
}

std::unique_ptr<ModelConfig> ModelFactory::Create(const std::string& name, const SNR& snr)
{
    const auto it = CreatorTable().find(name);

    if (it == CreatorTable().end()) throw ChemistryNotFound(name);

    return it->second->Create(snr);
}

bool ModelFactory::Register(const std::string& name, ModelCreator* const ctor)
{
    return CreatorTable().insert(std::make_pair(name, ctor)).second;
}

std::set<std::string> ModelFactory::SupportedChemistries()
{
    std::set<std::string> result;
    for (const auto& item : ModelFactory::CreatorTable())
        result.insert(item.first);
    return result;
}

std::map<std::string, ModelCreator*>& ModelFactory::CreatorTable()
{
    static std::map<std::string, ModelCreator*> tbl;
    return tbl;
}

}  // Consensus
}  // PacBio
