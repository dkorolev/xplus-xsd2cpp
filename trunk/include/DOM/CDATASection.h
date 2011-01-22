// This file is part of XmlPlus package
// 
// Copyright (C)   2010   Satya Prakash Tripathi
//
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __CDATA_SECTION_H__
#define __CDATA_SECTION_H__

#include "DOM/DOMCommonInc.h"

namespace DOM
{
  class CDATASection : public XPlus::XPlusObject
  {
    public:
    CDATASection():
    XPlusObject("CDATASection")
    {
    }

    virtual ~CDATASection() {}
  };
}

#endif