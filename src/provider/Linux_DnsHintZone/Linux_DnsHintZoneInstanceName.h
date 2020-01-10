// =======================================================================
// Linux_DnsHintZoneInstanceName.h
//     created on Thu, 23 Nov 2006 using ECUTE 2.2
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
#ifndef Linux_DnsHintZoneInstanceName_h
#define Linux_DnsHintZoneInstanceName_h

#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"
#include "ArrayConverter.h"
#include "CmpiErrorFormater.h"


namespace genProvider {

  class Linux_DnsHintZoneInstanceName {
       
    private:
    void init();
    void init(const Linux_DnsHintZoneInstanceName& anInstanceName);
    void reset();
       
    const char* m_CIMClassNameP;
    const char* m_nameSpaceP;
    
    const char* m_InstanceID;
    const char* m_Name;
       
    struct isSetType{
      unsigned int m_nameSpaceP:1;
      unsigned int InstanceID:1;
      unsigned int Name:1;

    } isSet;
  
    public:
    Linux_DnsHintZoneInstanceName();
  	
    Linux_DnsHintZoneInstanceName(const Linux_DnsHintZoneInstanceName& anInstanceName);
  	   
    Linux_DnsHintZoneInstanceName(const CmpiObjectPath& path);
  	 
    ~Linux_DnsHintZoneInstanceName();
       
    Linux_DnsHintZoneInstanceName& operator=(const Linux_DnsHintZoneInstanceName& anInstanceName);
       
    CmpiObjectPath getObjectPath() const;
       
    void fillKeys(CmpiInstance& cmpiInstance) const;
       
    unsigned int isNameSpaceSet() const;
    void setNamespace(const char* aNameSpaceP, int aCopyFlag = 1);
    const char* getNamespace() const;
    
    unsigned int isInstanceIDSet() const;
    void setInstanceID(const char* aValue, int aCopyFlag = 1);
    const char* getInstanceID() const;

    unsigned int isNameSet() const;
    void setName(const char* aValue, int aCopyFlag = 1);
    const char* getName() const;


  };
  
  //****************************************************************************
  struct Linux_DnsHintZoneInstanceNameEnumerationElement {
  	Linux_DnsHintZoneInstanceName* m_elementP;
  	Linux_DnsHintZoneInstanceNameEnumerationElement* m_nextP;
  	
  	Linux_DnsHintZoneInstanceNameEnumerationElement();
  	~Linux_DnsHintZoneInstanceNameEnumerationElement();  	
  };
  
  //****************************************************************************
  class Linux_DnsHintZoneInstanceNameEnumeration {
  
  	private:
    Linux_DnsHintZoneInstanceNameEnumerationElement* m_firstElementP;
  	Linux_DnsHintZoneInstanceNameEnumerationElement* m_currentElementP;
  	Linux_DnsHintZoneInstanceNameEnumerationElement* m_endElementP;
  	
  	public:
    Linux_DnsHintZoneInstanceNameEnumeration();
  	  
    Linux_DnsHintZoneInstanceNameEnumeration(const CmpiArray& arr);
  	  
    Linux_DnsHintZoneInstanceNameEnumeration(const Linux_DnsHintZoneInstanceNameEnumeration& anInstanceNameEnumeration);
  	   
    ~Linux_DnsHintZoneInstanceNameEnumeration();
  	  
    void reset();
  	  
    bool hasNext() const;
  	  
    const Linux_DnsHintZoneInstanceName& getNext();
  	  
    int getSize() const;
  	  
    const Linux_DnsHintZoneInstanceName& getElement(int anIndex) const;  	  
  	  
    //no copy of the element is done
    void addElement(const Linux_DnsHintZoneInstanceName& anInstanceName);
  	  
    operator CmpiArray() const;

  };

}
#endif

