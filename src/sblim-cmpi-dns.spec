#
# sblim-cmpi-dns.spec.in
#
# Package spec for cmpi-dns
#

%define cmpi_provider_dir %{_libdir}/cmpi

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}

Summary: SBLIM WBEM-SMT Dns 
Name: sblim-cmpi-dns
Version: 1.0
Release: 1
Group: Systems Management/Instrumentation
URL: http://www.sblim.org
License: EPL
Requires: sblim-tools-libra
Requires: bind 
BuildRequires: sblim-tools-libra-devel

Provides: sblim-cmpi-dns

Source0: http://prdownloads.sourceforge.net/sblim/%{name}-%{version}.tar.bz2

%Description
The cmpi-dns package provides access to the dns configuration data 
via CIMOM technology/infrastructure. 
It contains the Dns CIM Model, CMPI Provider with the Samba task specific 
Resource Access.
A web based client application is available on SourceForge. Please refer to
https://sourceforge.net/project/showfiles.php?group_id=128809&package_id=214076
to get the WBEM-SMT Client Application.

###############################################################################
%Package devel
Summary: SBLIM WBEM-SMT Dns - Header Development Files
Group: Systems Management/Instrumentation
Requires: %{name} = %{version}-%{release}

%Description devel
SBLIM WBEM-SMT Dns Development Package contains header files and
link libraries for dependent provider packages

###############################################################################
%Package test
Summary: SBLIM WBEM-SMT Dns - Testcase Files
Group: Systems Management/Instrumentation/Test
Requires: %{name} = %{version}-%{release}

%Description test
SBLIM WBEM-SMT DNS Provider Testcase Files for the SBLIM Testsuite

###############################################################################
%prep

%setup -n %{name}-%{version}
export PATCH_GET=0
#%patch0 -p0


###############################################################################
%build

%configure \
   TESTSUITEDIR=%{_datadir}/sblim-testsuite \
   CIMSERVER=pegasus \
   PROVIDERDIR=%{_libdir}/cmpi/ \
make


###############################################################################
%clean
if [ "x${RPM_BUILD_ROOT}" != "x" ] ; then
   rm -rf ${RPM_BUILD_ROOT}
fi


###############################################################################
%install
[ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT

make DESTDIR=$RPM_BUILD_ROOT install

# remove unused libtool files
rm -f $RPM_BUILD_ROOT/%{_libdir}/*a
rm -f $RPM_BUILD_ROOT/%{_libdir}/cmpi/*a


###############################################################################
%pre
# Conditional definition of schema and registration files
%define SCHEMA %{_datadir}/%{name}/Linux_Dns_Profile.mof %{_datadir}/%{name}/Linux_Dns.mof
%define REGISTRATION %{_datadir}/%{name}/Linux_Dns.registration

%define INTEROP_SCHEMAS %{_datadir}/%{name}/Linux_Dns_Profile.mof
%define INTEROP_REGISTRATIONS %{_datadir}/%{name}/Linux_Dns_Profile.registration

# If upgrading, deregister old version
if [ $1 -gt 1 ]
then
  %{_datadir}/%{name}/provider-register.sh -d %{?tog_pegasus:-t pegasus} \
	-r %{REGISTRATION} -m %{SCHEMA} > /dev/null
	
  %{_datadir}/%{name}/provider-register.sh -d %{?tog_pegasus:-t pegasus} \
	-n root/PG_InterOp -r %{INTEROP_REGISTRATIONS} -m %{INTEROP_SCHEMAS} > /dev/null		
fi


###############################################################################
%post
# Register Schema and Provider - this is highly provider specific

# Check if pegasus repository has the CIM_RegisteredProfile classes else register the interop mof file   
#if [ ! -e "/var/lib/Pegasus/repository/root#PG_InterOp/classes/CIM_RegisteredProfile.CIM_ManagedElement" ]
#then
#	if [ -e "/usr/share/Pegasus/mof/CIM29/CIM_Interop.mof" ]
#	then		
#		cimmofl -w -uc -aEV -R/var/lib/Pegasus -n root/PG_InterOp /usr/share/Pegasus/mof/CIM29/CIM_Interop.mof > /dev/null		
#		/etc/init.d/tog-pegasus restart	> /dev/null
#	fi
#fi	

%{_datadir}/%{name}/provider-register.sh %{?tog_pegasus:-t pegasus} \
	-v -r %{REGISTRATION} -m %{SCHEMA} > /dev/null

%{_datadir}/%{name}/provider-register.sh %{?tog_pegasus:-t pegasus} \
	-v -n root/PG_InterOp -r %{INTEROP_REGISTRATIONS} -m %{INTEROP_SCHEMAS} > /dev/null	

/sbin/ldconfig


###############################################################################
%preun
# Deregister only if not upgrading 
if [ $1 -eq 0 ]
then
  %{_datadir}/%{name}/provider-register.sh -d %{?tog_pegasus:-t pegasus} \
	-r %{REGISTRATION} -m %{SCHEMA} > /dev/null
	
  %{_datadir}/%{name}/provider-register.sh -d %{?tog_pegasus:-t pegasus} \
	-n root/PG_InterOp -r %{INTEROP_REGISTRATIONS} -m %{INTEROP_SCHEMAS} > /dev/null		
fi


###############################################################################
%postun 
# Run ldconfig only if not upgrading
if [ $1 -eq 0 ]
then
  /sbin/ldconfig
fi


###############################################################################
%files
%defattr(-,root,root,0644) 
%doc %{_datadir}/doc/%{name}-%{version}
%doc %{_mandir}/man5/smt_dns_ra_support.conf.5.gz
%config(noreplace) %{_sysconfdir}/smt_dns*.conf
%defattr(-,root,root,0755)
%{_datadir}/%{name}
%{_libdir}/libIBM_DnsProviderTooling.so.*
%{_libdir}/libLinux_DnsGeneralProviderBasic.so.*
%{_libdir}/libRaToolsDns.so.*
%{cmpi_provider_dir}/libcmpiDnsCIM_ConcreteJob.so
%{cmpi_provider_dir}/libcmpiLinux_Dns*.so


%files devel
%defattr(-,root,root) 
%dir %{_includedir}/sblim
%{_includedir}/sblim/smt_dns*.h
%{_libdir}/libIBM_DnsProviderTooling.so
%{_libdir}/libLinux_DnsGeneralProviderBasic.so
%{_libdir}/libRaToolsDns.so

%files test
%defattr(-,root,root,0755)
%{_datadir}/sblim-testsuite/test-cmpi-dns.sh
%defattr(-,root,root,0644)
%{_datadir}/sblim-testsuite/buffalo.example2.com.conf
%{_datadir}/sblim-testsuite/cobra.example1.com.conf
%{_datadir}/sblim-testsuite/elephant.example2.com.conf
%{_datadir}/sblim-testsuite/named.conf
%{_datadir}/sblim-testsuite/rhino.example1.com.conf
%{_datadir}/sblim-testsuite/testlocaldomain.zone
%{_datadir}/sblim-testsuite/testlocalhost.zone
%{_datadir}/sblim-testsuite/testnamed.broadcast
%{_datadir}/sblim-testsuite/testnamed.ca
%{_datadir}/sblim-testsuite/testnamed.ip6.local
%{_datadir}/sblim-testsuite/testnamed.local
%{_datadir}/sblim-testsuite/testnamed.zero
%{_datadir}/sblim-testsuite/cim/Linux_Dns*
%{_datadir}/sblim-testsuite/system/linux/Linux_Dns*


###############################################################################
%changelog
* Wed Jun 17 2009 Jeremy Bongio <jbongio@us.ibm.com> 0.5.6-1
    o Maintenance release

* Mon May 12 2008 Saravanan Kannan <skanan(at)us.ibm.com> 0.5.5-1
    o Fixes for testsuite issues
    
* Wed Apr 30 2008 Saravanan Kannan <skanan(at)us.ibm.com>  0.5.4-1
    o 1939841  cmpi-dns: Registered Profile support 
    
* Tue Dec 11 2007 Sam Kannan <skanan@us.ibm.com> 0.5.4-1
    o 1845494  cmpi-dns: Include proper group definition for RPM build
    o 1815304  cmpi-dns: Man page for the dns specific config file
    o 1814089  cmpi-dns: Enhancements to build process

* Tue Dec 11 2007 Sam Kannan <skanan@us.ibm.com> 0.5.3-1
    o 1845494  cmpi-dns: Include proper group definition for RPM build
    o 1815304  cmpi-dns: Man page for the dns specific config file
    o 1814089  cmpi-dns: Enhancements to build process

* Fri Sep 14 2007 Wolfgang Taphorn <taphorn@de.ibm.com> 0.5.2-1
    o 1794680  cmpi-dns: base tests on current delivered testsuite
    o 1794655  cmpi-dns: Include information on WBEM-SMT client app

* Tue Aug 21 2007 Wolfgang Taphorn <taphorn@de.ibm.com> - 0.5.1-1
    o 1778811  cmpi-dns: wrong file permisssions to config files
    o 1778739  cmpi-dns: port for masters is not set properly
    o 1777802  cmpi-dns: returning undefined error codes

* Fri Jul 6 2007 Wolfgang Taphorn <taphorn@de.ibm.com> 0.5.0-1
  - Inclusion of fixes for the following issues:
    o 1764890  cmpi-dns: More specific on package content
    o 1763586  cmpi-dns: Empty String arrays are not processed correct
    o 1762058  cmpi-dns: Type conversion issue for string arrays
    o 1747731  cmpi-dns: Model upgrade for ECUTE 2.3.6 usage
    o 1746642  cmpi-dns: Cleanup for test cases
    o 1741423  cmpi-dns: modifyInst attribute is required for new TestSuite
    o 1741419  cmpi-dns: objectPath in test cases is incomplete
    o 1741418  cmpi-dns: reordered the test cases
    o 1739179  cmpi-dns: Unresolved symbols in service class

* Mon Dec 4 2006 Wolfgang Taphorn <taphorn@de.ibm.com> 0.2.3-1
  - Inclusion of fixes for the following bug entries:
    o 1608730  cmpi-dns: Build does not pass 'make distcheck'
    o 1608764  cmpi-dns: Adding test cases
    o 1608767  cmpi-dns: Model changes

* Tue Sep 08 2005 Wolfgang Taphorn <taphorn@de.ibm.com>
  - initial support
  
