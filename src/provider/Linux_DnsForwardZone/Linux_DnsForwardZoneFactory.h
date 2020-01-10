// =======================================================================
// Linux_DnsForwardZoneFactory.h
//     created on Wed, 29 Nov 2006 using ECUTE 2.2
// 
// Copyright (c) 2006, 2009, International Business Machines
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://www.opensource.org/licenses/eclipse-1.0.php
//
// Author:        generated
//
// Contributors:
//                Wolfgang Taphorn   <taphorn at de.ibm.com>
//                Murillo Bernardes  <bernarde(at)br.ibm.com>
//                Mukunda Chowdaiah  <cmukunda(at)in.ibm.com>
//                Ashoka S Rao       <ashoka.rao(at)in.ibm.com>
//
// =======================================================================
//
// 
#ifndef Linux_DnsForwardZoneFactory_h
#define Linux_DnsForwardZoneFactory_h


#include "Linux_DnsForwardZoneInterface.h"

namespace genProvider{
	
  class Linux_DnsForwardZoneFactory {

    public:
	  Linux_DnsForwardZoneFactory() {};
	  ~Linux_DnsForwardZoneFactory() {};
	
	  static Linux_DnsForwardZoneInterface* getImplementation();

    };
    
}

#endif
