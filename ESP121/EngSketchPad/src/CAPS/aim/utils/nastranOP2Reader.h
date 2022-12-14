/* Generated by Cython 0.29.30 */

#ifndef __PYX_HAVE__nastranOP2Reader
#define __PYX_HAVE__nastranOP2Reader

#include "Python.h"
#include "egadsTypes.h"
#include "egads.h"
#include "egadsErrors.h"
#include "prm.h"
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#ifndef __PYX_HAVE_API__nastranOP2Reader

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#ifndef DL_IMPORT
  #define DL_IMPORT(_T) _T
#endif

__PYX_EXTERN_C int nastran_getObjective(char const *, int *, double **);

#endif /* !__PYX_HAVE_API__nastranOP2Reader */

/* WARNING: the interface of the module init function changed in CPython 3.5. */
/* It now returns a PyModuleDef instance instead of a PyModule instance. */

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initnastranOP2Reader(void);
#else
PyMODINIT_FUNC PyInit_nastranOP2Reader(void);
#endif

#endif /* !__PYX_HAVE__nastranOP2Reader */
