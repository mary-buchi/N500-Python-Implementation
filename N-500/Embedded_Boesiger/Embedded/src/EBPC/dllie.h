//	/*=======================================================
//	 * Copyright  : EPS AG, Gallusstr. 10,
//					9500 Wil, Switzerland.
//	 *
//	 * Filename   : dllie.h
//	 * System     :	
//	 * Function   : switches between dllimport/dllexport directives when 
//					preprocessing DLL interfaces
//
//	 * Author     :	M. Sutter
//	 * References :
//	 * Contents   :
//
//	*=======================================================*/

#ifndef dllie_h
#define dllie_h 1


// Macro definitions for Core Components
// -------------------------------------
#ifdef BUILD_EBET
  #define EBET_DLL_DECL	__declspec(dllexport)
#else
  #define EBET_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBCO
  #define EBCO_DLL_DECL	__declspec(dllexport)
#else
  #define EBCO_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBPI
  #define EBPI_DLL_DECL	__declspec(dllexport)
#else
  #define EBPI_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBSY
  #define EBSY_DLL_DECL	__declspec(dllexport)
#else
  #define EBSY_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBST
  #define EBST_DLL_DECL	__declspec(dllexport)
#else
  #define EBST_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBMC
  #define EBMC_DLL_DECL	__declspec(dllexport)
#else
  #define EBMC_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBWC
  #define EBWC_DLL_DECL	__declspec(dllexport)
#else
  #define EBWC_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBTC
  #define EBTC_DLL_DECL	__declspec(dllexport)
#else
  #define EBTC_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBPC
  #define EBPC_DLL_DECL	__declspec(dllexport)
#else
  #define EBPC_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBPO
  #define EBPO_DLL_DECL	__declspec(dllexport)
#else
  #define EBPO_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBES
  #define EBES_DLL_DECL	__declspec(dllexport)
#else
  #define EBES_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBIO
  #define EBIO_DLL_DECL	__declspec(dllexport)
#else
  #define EBIO_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBDI
  #define EBDI_DLL_DECL	__declspec(dllexport)
#else
  #define EBDI_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBHI
  #define EBHI_DLL_DECL	__declspec(dllexport)
#else
  #define EBHI_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBISR
  #define EBISR_DLL_DECL	__declspec(dllexport)
#else
  #define EBISR_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBI2CTEMP
  #define EBI2CTEMP_DLL_DECL	__declspec(dllexport)
#else
  #define EBI2CTEMP_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBI2CEPROM
  #define EBI2CEPROM_DLL_DECL	__declspec(dllexport)
#else
  #define EBI2CEPROM_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBI2CADC
  #define EBI2CADC_DLL_DECL	__declspec(dllexport)
#else
  #define EBI2CADC_DLL_DECL	__declspec(dllimport)
#endif

#ifdef BUILD_EBI2CDP
  #define EBI2CDP_DLL_DECL	__declspec(dllexport)
#else
  #define EBI2CDP_DLL_DECL	__declspec(dllimport)
#endif

#endif
