// =======================================================================
// Linux_DnsAllowQueryForZoneRepositoryInstance.h
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
#ifndef Linux_DnsAllowQueryForZoneRepositoryInstance_h
#define Linux_DnsAllowQueryForZoneRepositoryInstance_h


#include "cmpidt.h"
#include "CmpiObjectPath.h"
#include "CmpiInstance.h"
#include "CmpiBooleanData.h"
#include "CmpiCharData.h"
#include "CmpiDateTime.h"

#include "Linux_DnsAllowQueryForZoneInstanceName.h"


namespace genProvider {

  class Linux_DnsAllowQueryForZoneRepositoryInstance {
       
    private:
    void init();
    void init(const Linux_DnsAllowQueryForZoneRepositoryInstance& anInstance);
    void reset();
       
    Linux_DnsAllowQueryForZoneInstanceName m_instanceName;
       
    struct isSetType{
      unsigned int instanceName:1;

    } isSet;
    
    public:
    Linux_DnsAllowQueryForZoneRepositoryInstance();
    Linux_DnsAllowQueryForZoneRepositoryInstance(
      const Linux_DnsAllowQueryForZoneRepositoryInstance& anInstance);
    Linux_DnsAllowQueryForZoneRepositoryInstance(
      const CmpiInstance& aCmpiInstance, 
      const char* anInstanceNamespaceP);
    ~Linux_DnsAllowQueryForZoneRepositoryInstance();
       
    Linux_DnsAllowQueryForZoneRepositoryInstance& operator=(
      const Linux_DnsAllowQueryForZoneRepositoryInstance& anInstance);
       
    CmpiInstance getCmpiInstance(const char** aPropertiesPP = 0) const;
    unsigned int isInstanceNameSet() const;
    void setInstanceName(const Linux_DnsAllowQueryForZoneInstanceName& anInstanceName);        
    const Linux_DnsAllowQueryForZoneInstanceName& getInstanceName() const;


  };
  
  struct Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement {

    Linux_DnsAllowQueryForZoneRepositoryInstance* m_elementP;
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement* m_nextP;

    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement();
    ~Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement();  

  };
  

  class Linux_DnsAllowQueryForZoneRepositoryInstanceEnumeration {

    private:
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement* m_firstElementP;
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement* m_currentElementP;
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumerationElement* m_endElementP;

    public:
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumeration();
    Linux_DnsAllowQueryForZoneRepositoryInstanceEnumeration(
      const Linux_DnsAllowQueryForZoneRepositoryInstanceEnumeration& anInstanceEnumeration);
    ~Linux_DnsAllowQueryForZoneRepositoryInstanceEnumeration();

    void reset();
    bool hasNext() const;
    const Linux_DnsAllowQueryForZoneRepositoryInstance& getNext();
    int getSize() const;
    const Linux_DnsAllowQueryForZoneRepositoryInstance& getElement(int anIndex) const;  	  
    void addElement(const Linux_DnsAllowQueryForZoneRepositoryInstance& anInstance);

  };

}

#endif
