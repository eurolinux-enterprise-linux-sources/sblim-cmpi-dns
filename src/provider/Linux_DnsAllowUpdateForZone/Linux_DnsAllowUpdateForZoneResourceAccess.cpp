// =======================================================================
// Linux_DnsAllowUpdateForZoneResourceAccess.cpp
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
#include "Linux_DnsAllowUpdateForZoneResourceAccess.h"
#include <string>
#include <list>

#include "smt_dns_ra_support.h"
#include "smt_dns_defaultvalues.h"
#include "smt_dns_array.h"
#include "smt_dns_valuemap.h"

namespace genProvider {
  
  static void setInstanceNameProperties(
      const char *aNameSpaceP,
      const char *optionName,
      const char *zoneName,
      Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName) {

      Linux_DnsAddressMatchListInstanceName  partComponent;
      Linux_DnsZoneInstanceName     groupComponent;

      //ACL
      partComponent.setNamespace(aNameSpaceP);
      partComponent.setName(optionName);
      partComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      //Service
      groupComponent.setNamespace(aNameSpaceP);
      groupComponent.setName(zoneName);
      groupComponent.setInstanceID( DEFAULT_INSTANCE_ID );

      anInstanceName.setNamespace(aNameSpaceP);
      anInstanceName.setGroupComponent(groupComponent);
      anInstanceName.setPartComponent(partComponent);
  }


  static void setInstanceProperties(
      const Linux_DnsAllowUpdateForZoneInstanceName anInstanceName,
      Linux_DnsAllowUpdateForZoneManualInstance& aManualInstance) {

      aManualInstance.setInstanceName(anInstanceName);
  }

  //----------------------------------------------------------------------------
  //Linux_DnsAllowUpdateForZoneResourceAccess::Linux_DnsAllowUpdateForZoneResourceAccess();

  //----------------------------------------------------------------------------
  Linux_DnsAllowUpdateForZoneResourceAccess::~Linux_DnsAllowUpdateForZoneResourceAccess() { }
    
  // intrinsic methods
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowUpdateForZoneResourceAccess::enumInstanceNames(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     Linux_DnsAllowUpdateForZoneInstanceNameEnumeration& anInstanceNameEnumeration) {
      
#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::enumInstanceNames" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        Linux_DnsAllowUpdateForZoneInstanceName anInstanceName;
        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), zones->zoneName, anInstanceName);
        anInstanceNameEnumeration.addElement(anInstanceName);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::enumInstanceNames" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowUpdateForZoneResourceAccess::enumInstances(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
     const char* aNameSpaceP,
     const char** aPropertiesPP,
  	 Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration) { 

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::enumInstances" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        Linux_DnsAllowUpdateForZoneInstanceName anInstanceName;
        Linux_DnsAllowUpdateForZoneManualInstance aManualInstance;

        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::enumInstances" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  Linux_DnsAllowUpdateForZoneManualInstance 
  Linux_DnsAllowUpdateForZoneResourceAccess::getInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const char** aPropertiesPP,
    const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::getInstance" << endl;
#endif

    Linux_DnsAllowUpdateForZoneManualInstance aManualInstance;

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;
    int found = 0;

    if (zones) {
      for (; zones->zoneName; zones++) {
        ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");
        if (zopts) {
          string optionName = "zone::";
          optionName.append(zones->zoneName);
          optionName.append("::allow-update");

          if (strcmp(optionName.c_str(), anInstanceName.getPartComponent().getName()) == 0 &&
              strcmp(zones->zoneName, anInstanceName.getGroupComponent().getName()) == 0) {

              setInstanceProperties(anInstanceName, aManualInstance);
              found = 1;
          }
        }
      }
    }
    if (zonesStart) freeZones( zonesStart );

    if(found == 0)
        throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"The specified instance does not exist!");

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::getInstance" << endl;
#endif
     return aManualInstance;
  }
  //----------------------------------------------------------------------------
  /*
  void
  Linux_DnsAllowUpdateForZoneResourceAccess::setInstance(
     const CmpiContext& aContext,
     const CmpiBroker& aBroker,
     const char** aPropertiesPP,
     const Linux_DnsAllowUpdateForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::setInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::setInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  /*
  Linux_DnsAllowUpdateForZoneInstanceName
  Linux_DnsAllowUpdateForZoneResourceAccess::createInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowUpdateForZoneManualInstance& aManualInstance) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::createInstance" << endl;
#endif

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::createInstance" << endl;
#endif
  }
  */
  
  //----------------------------------------------------------------------------
  void
  Linux_DnsAllowUpdateForZoneResourceAccess::deleteInstance(
    const CmpiContext& aContext,
    const CmpiBroker& aBroker,
    const Linux_DnsAllowUpdateForZoneInstanceName& anInstanceName) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::deleteInstance" << endl;
#endif

    string partName = anInstanceName.getPartComponent().getName();
    string groupName = anInstanceName.getGroupComponent().getName();
    int deleted = 0;

    if (!partName.c_str() || !groupName.c_str())
        throw CmpiStatus(CMPI_RC_ERR_INVALID_PARAMETER, "The submitted instance name is not valid!");

    string parentName = partName.substr(0, partName.find_first_of("::"));
    partName.erase(0,partName.find_first_of("::")+2);

    if (strcmp("zone", parentName.c_str()) == 0) {
        DNSZONE *zones = getZones();
        DNSZONE *zonesStart = zones;
        string zoneName = partName.substr(0, partName.find_first_of("::"));
        string optionName = partName.substr(partName.find_first_of("::")+2, partName.length());

       if (strcmp(optionName.c_str(), "allow-update") != 0)
         throw CmpiStatus(CMPI_RC_ERR_FAILED,"The submitted instance name does not specify a allow-update instance!");

        while(zones && zones->zoneName) {
          if (strcmp(zones->zoneName, groupName.c_str()) == 0) {
            if (findOptsInZone(zones, optionName.c_str())) {
              delOptsFromZone(zones, optionName.c_str());
              deleted = 1;
            }
          }
          zones++;
        }
        if(zonesStart)freeZones(zonesStart);

    } else {
      throw CmpiStatus(CMPI_RC_ERR_FAILED,"The specified instance defines a not supported allow-update attribute!");
    }

    if (deleted == 0) {
      throw CmpiStatus(CMPI_RC_ERR_NOT_FOUND,"An instance could not be found for the submitted instance name!");
    }

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::deleteInstance" << endl;
#endif
  }
	

  // Association Interface
  //----------------------------------------------------------------------------
  void Linux_DnsAllowUpdateForZoneResourceAccess::referencesGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::referencesGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        if (strcmp(optionName.c_str(), aSourceInstanceName.getName()) != 0) {
          zones++;
          continue;
        }

        Linux_DnsAllowUpdateForZoneInstanceName anInstanceName;
        Linux_DnsAllowUpdateForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::referencesGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowUpdateForZoneResourceAccess::referencesPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsAllowUpdateForZoneManualInstanceEnumeration& aManualInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::referencesPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        Linux_DnsAllowUpdateForZoneInstanceName anInstanceName;
        Linux_DnsAllowUpdateForZoneManualInstance aManualInstance;
        setInstanceNameProperties(aNameSpaceP, optionName.c_str(), zones->zoneName, anInstanceName);
        setInstanceProperties(anInstanceName, aManualInstance);
        aManualInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);
#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::referencesPartComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowUpdateForZoneResourceAccess::associatorsGroupComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsAddressMatchListInstanceName& aSourceInstanceName,
    Linux_DnsZoneInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::associatorsGroupComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        Linux_DnsZoneInstanceName anInstanceName;
        Linux_DnsZoneInstance     aManualInstance;

        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        if (strcmp(optionName.c_str(), aSourceInstanceName.getName()) != 0) {
          zones++;
          continue;
        }

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(zones->zoneName);
        anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

        aManualInstance.setInstanceName(anInstanceName);
        if (strcmp(zones->zoneType,"master") == 0) aManualInstance.setType(1);
        else if (strcmp(zones->zoneType,"slave") == 0) aManualInstance.setType(2);
        else if (strcmp(zones->zoneType,"stub") == 0) aManualInstance.setType(3);
        else if (strcmp(zones->zoneType,"forward") == 0) aManualInstance.setType(4);
        else if (strcmp(zones->zoneType,"hint") == 0) aManualInstance.setType(5);
        else aManualInstance.setType(0);

        anInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::associatorsGroupComponent" << endl;
#endif
  }
  
  //----------------------------------------------------------------------------
  void Linux_DnsAllowUpdateForZoneResourceAccess::associatorsPartComponent( 
    const CmpiContext& aContext,  
    const CmpiBroker& aBroker,
    const char* aNameSpaceP,
    const char** aPropertiesPP,
    const Linux_DnsZoneInstanceName& aSourceInstanceName,
    Linux_DnsAddressMatchListInstanceEnumeration& anInstanceEnumeration) {

#ifdef DEBUG
     cout << "entering Linux_DnsAllowUpdateForZone::associatorsPartComponent" << endl;
#endif

    DNSZONE *zones = getZones();
    DNSZONE *zonesStart = zones;

    while(zones && zones->zoneName) {
      if (strcmp(zones->zoneName, aSourceInstanceName.getName()) != 0) {
        zones++;
        continue;
      }

      ZONEOPTS* zopts = findOptsInZone(zones,"allow-update");

      if (zopts) {
        Linux_DnsAddressMatchListInstanceName anInstanceName;
        Linux_DnsAddressMatchListInstance     aManualInstance;

        string optionName = "zone::";
        optionName.append(zones->zoneName);
        optionName.append("::allow-update");

        anInstanceName.setNamespace(aNameSpaceP);
        anInstanceName.setName(optionName.c_str());
        anInstanceName.setInstanceID(DEFAULT_INSTANCE_ID);

        aManualInstance.setInstanceName(anInstanceName);

        DnsArray da = DnsArray( zopts->value );
        aManualInstance.setAddressMatchListElement( da.toArray(), da.size() );

        CMPIUint8* aclType = new CMPIUint8[da.size()];
        DnsArrayConstIterator iter;
        int i = 0;

        for ( iter = da.begin(); iter != da.end(); ++iter) {
            aclType[i++] = getACLType((*iter).c_str());
        }
        aManualInstance.setAddressMatchListElementType (aclType, da.size() );
        anInstanceEnumeration.addElement(aManualInstance);
      }
      zones++;
    }
    if (zonesStart) freeZones(zonesStart);

#ifdef DEBUG
     cout << "exiting Linux_DnsAllowUpdateForZone::associatorsPartComponent" << endl;
#endif
  }
   
  
  // extrinsic methods

	
}

