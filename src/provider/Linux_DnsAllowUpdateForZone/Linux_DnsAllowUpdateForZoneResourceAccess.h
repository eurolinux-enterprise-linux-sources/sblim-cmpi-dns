// =======================================================================
// Linux_DnsAllowUpdateForZoneResourceAccess.h
//     created on Thu, 26 Oct 2006 using ECUTE 2.2
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
#ifndef Linux_DnsAllowUpdateForZoneResourceAccess_h
#define Linux_DnsAllowUpdateForZoneResourceAccess_h

#include "Linux_DnsAllowUpdateForZoneInstanceName.h"
#include "Linux_DnsAllowUpdateForZoneManualInstance.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiDateTime.h"
#include "CmpiBroker.h"
#include "Linux_DnsZoneInstance.h"
#include "Linux_DnsAddressMatchListInstance.h"
#include "Linux_DnsZoneExternal.h"
#include "Linux_DnsAddressMatchListExternal.h"
#include "Linux_DnsAllowUpdateForZoneDefaultImplementation.h"


namespace genProvider {

  class Linux_DnsAllowUpdateForZoneResourceAccess:
   public Linux_DnsAllowUpdateForZoneDefaultImplementation {
  	
    public:
    /*
    Linux_DnsAllowUpdateForZoneResourceAccess();
    */    
    virtual ~Linux_DnsAllowUpdateForZoneResourceAccess() ;
    
    /* intrinsic methods */
    virtual void enumInstanceNames(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      Linux_DnsAllowUpdateForZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	
    virtual void enumInstances(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
  	  Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration);
  	
    virtual Linux_DnsAllowUpdateForZoneManualInstance getInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);
  	
    /*
    virtual void setInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const char** aPropertiesPP,
      const Linux_DnsAllowUpdateForZoneManualInstance& aManualInstance);
    */
  	
    /*
    virtual Linux_DnsAllowUpdateForZoneInstanceName createInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowUpdateForZoneManualInstance& aManualInstance);
    */
  	
    virtual void deleteInstance(
      const CmpiContext& aContext,
      const CmpiBroker& aBroker,
      const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName);
	
    
    /* Association Interface */

    virtual void referencesGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void referencesPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration);

    virtual void associatorsGroupComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
      Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration);

    virtual void associatorsPartComponent( 
      const CmpiContext& aContext,  
      const CmpiBroker& aBroker,
      const char* aNameSpaceP,
      const char** aPropertiesPP,
      const Linux_DnsZoneInstanceName& aSourceInstanceName,
      Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration);

   
    
    /* extrinsic methods */
    
	
  };
  
}
#endif
