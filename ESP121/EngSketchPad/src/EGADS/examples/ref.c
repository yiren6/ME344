/*
 *      EGADS: Electronic Geometry Aircraft Design System
 *
 *             Look at references of an Object
 *
 *      Copyright 2011-2022, Massachusetts Institute of Technology
 *      Licensed under The GNU Lesser General Public License, version 2.1
 *      See http://www.opensource.org/licenses/lgpl-2.1.php
 *
 */

#include "egads.h"

extern int EG_referenceObjects(ego object, int *nobj, ego **objs);


static void
parseOut(int level, ego object, int sense)
{
  int    i, stat, oclass, mtype, nobjs, periodic, *senses, *ivec;
  ego    prev, next, geom, top, *objs;
  double limits[4], *rvec;
  long unsigned int pointer;
  static char *classType[27] = {"CONTEXT", "TRANSFORM", "TESSELLATION",
                                "NIL", "EMPTY", "REFERENCE", "", "",
                                "", "", "PCURVE", "CURVE", "SURFACE", "", 
                                "", "", "", "", "", "", "NODE",
                                "EGDE", "LOOP", "FACE", "SHELL",
                                "BODY", "MODEL"};
  static char *curvType[9] = {"Line", "Circle", "Ellipse", "Parabola",
                              "Hyperbola", "Trimmed", "Bezier", "BSpline", 
                              "Offset"};
  static char *surfType[11] = {"Plane", "Spherical", "Cylinder", "Revolution",
                               "Toroidal", "Trimmed" , "Bezier", "BSpline", 
                               "Offset", "Conical", "Extrusion"};
  
  pointer = (long unsigned int) object;
  stat = EG_getInfo(object, &oclass, &mtype, &top, &prev, &next);
  if (stat != EGADS_SUCCESS) {
    printf(" parseOut: %d EG_getInfo return = %d\n", level, stat);
    return;
  }
  
  /* geometry */
  if ((oclass >= PCURVE) && (oclass <= SURFACE)) {
    stat = EG_getGeometry(object, &oclass, &mtype, &geom, &ivec, &rvec);
    if (stat != EGADS_SUCCESS) {
      printf(" parseOut: %d EG_getGeometry return = %d\n", level, stat);
      return;
    }
    stat = EG_getRange(object, limits, &periodic);

    /* output most data except the axes info */
    if (oclass != SURFACE) {

      for (i = 0; i < 2*level; i++) printf(" ");
      printf("%s %lx  range = %le %le  per = %d\n", 
             classType[oclass], pointer, limits[0], limits[1], periodic);

      for (i = 0; i < 2*level+2; i++) printf(" ");
      if (oclass == PCURVE) {
        switch (mtype) {
          case CIRCLE:
            printf("%s  radius = %lf\n", curvType[mtype-1], rvec[6]);
            break;
          case ELLIPSE:
            printf("%s  major = %lf, minor = %lf\n", 
                   curvType[mtype-1], rvec[6], rvec[7]);
            break;
          case PARABOLA:
            printf("%s  focus = %lf\n", curvType[mtype-1], rvec[6]);
            break;
          case HYPERBOLA:
            printf("%s  major = %lf, minor = %lf\n", 
                   curvType[mtype-1], rvec[6], rvec[7]);
            break;
          case TRIMMED:
            printf("%s  first = %lf, last = %lf\n", 
                   curvType[mtype-1], rvec[0], rvec[1]);
            break;
          case BEZIER:
            printf("%s  flags = %x, degree = %d, #CPs = %d\n", 
                   curvType[mtype-1], ivec[0], ivec[1], ivec[2]);
            break;       
          case BSPLINE:
            printf("%s  flags = %x, degree = %d, #CPs = %d, #knots = %d\n", 
                   curvType[mtype-1], ivec[0], ivec[1], ivec[2], ivec[3]);
            break;
          case OFFSET:
            printf("%s  offset = %lf\n", curvType[mtype-1], rvec[0]);
            break;
          case 0:
            printf("unknown curve type!\n");
            break;
          default:
            printf("%s   %lf %lf   %lf %lf\n", curvType[mtype-1],
                   rvec[0], rvec[1], rvec[2], rvec[3]);
        }
      } else {
        switch (mtype) {
          case CIRCLE:
            printf("%s  radius = %lf\n", curvType[mtype-1], rvec[9]);
            break;
          case ELLIPSE:
            printf("%s  major = %lf, minor = %lf\n", 
                   curvType[mtype-1], rvec[9], rvec[10]);
            break;
          case PARABOLA:
            printf("%s  focus = %lf\n", curvType[mtype-1], rvec[9]);
            break;
          case HYPERBOLA:
            printf("%s  major = %lf, minor = %lf\n", 
                   curvType[mtype-1], rvec[9], rvec[10]);
            break;
          case TRIMMED:
            printf("%s  first = %lf, last = %lf\n", 
                   curvType[mtype-1], rvec[0], rvec[1]);
            break;
          case BEZIER:
            printf("%s  flags = %x, degree = %d, #CPs = %d\n", 
                   curvType[mtype-1], ivec[0], ivec[1], ivec[2]);
            break;       
          case BSPLINE:
            printf("%s  flags = %x, degree = %d, #CPs = %d, #knots = %d\n", 
                   curvType[mtype-1], ivec[0], ivec[1], ivec[2], ivec[3]);
            break;
          case OFFSET:
            printf("%s  offset = %lf\n", curvType[mtype-1], rvec[3]);
            break;
          case 0:
            printf("unknown curve type!\n");
            break;
          default:
            printf("%s\n", curvType[mtype-1]);
        }
      }

    } else {
    
      for (i = 0; i < 2*level; i++) printf(" ");
      printf("%s %lx  Urange = %le %le  Vrange = %le %le  per = %d\n", 
             classType[oclass], pointer, limits[0], limits[1], 
                                         limits[2], limits[3], periodic);

      for (i = 0; i < 2*level+2; i++) printf(" ");
      switch (mtype) {
        case SPHERICAL:
          printf("%s  radius = %lf\n", surfType[mtype-1], rvec[9]);
          break;
        case CONICAL:
          printf("%s  angle = %lf, radius = %lf\n", 
                 surfType[mtype-1], rvec[12], rvec[13]);
          printf("    rvec = %lf %lf %lf   %lf %lf %lf  \n", 
                 rvec[0], rvec[1], rvec[2], rvec[3], rvec[4],  rvec[5]);
          printf("           %lf %lf %lf   %lf %lf %lf  \n", 
                 rvec[6], rvec[7], rvec[8], rvec[9], rvec[10], rvec[11]);
          break;
        case CYLINDRICAL:
          printf("%s  radius = %lf\n", surfType[mtype-1], rvec[12]);
          break;
        case TOROIDAL:
          printf("%s  major = %lf, minor = %lf\n", 
                 surfType[mtype-1], rvec[12], rvec[13]);
          break;
        case BEZIER:
          printf("%s  flags = %x, U deg = %d #CPs = %d, V deg = %d #CPs = %d\n", 
                 surfType[mtype-1], ivec[0], ivec[1], ivec[2], ivec[3], ivec[4]);
          break;
        case BSPLINE:
          printf("%s  flags = %x, U deg = %d #CPs = %d #knots = %d ",
                 surfType[mtype-1], ivec[0], ivec[1], ivec[2], ivec[3]);
          printf(" V deg = %d #CPs = %d #knots = %d\n",
                 ivec[4], ivec[5], ivec[6]);
          break;
        case TRIMMED:
          printf("%s  U trim = %lf %lf, V trim = %lf %lf\n", 
                 surfType[mtype-1], rvec[0], rvec[1], rvec[2], rvec[3]);
          break;
        case OFFSET:
          printf("%s  offset = %lf\n", surfType[mtype-1], rvec[0]);
          break;
        case 0:
          printf("unknown surface type!\n");
          break;
        default:
          printf("%s\n", surfType[mtype-1]);
      }
    }

    if (ivec != NULL) EG_free(ivec);
    if (rvec != NULL) EG_free(rvec);
    if (geom != NULL) parseOut(level+1, geom, 0);
    return;
  }

  /* output class and pointer data */

  for (i = 0; i < 2*level; i++) printf(" ");
  if (sense == 0) {
    printf("%s %lx\n", classType[oclass], pointer);
  } else {
    printf("%s %lx  sense = %d\n", classType[oclass], pointer, sense);
  }

  /* topology*/
  if ((oclass >= NODE) && (oclass <= MODEL)) {
    stat = EG_getTopology(object, &geom, &oclass, &mtype, limits, &nobjs,
                          &objs, &senses);
    if (stat != EGADS_SUCCESS) {
      printf(" parseOut: %d EG_getTopology return = %d\n", level, stat);
      return;
    }
    if (oclass == NODE) {
      for (i = 0; i < 2*level+2; i++) printf(" ");
      printf("XYZ = %lf %lf %lf\n", limits[0], limits[1], limits[2]);
    } else if (oclass == EDGE) {
      for (i = 0; i < 2*level+2; i++) printf(" ");
      if (mtype == DEGENERATE) {
        printf("tRange = %lf %lf -- Degenerate!\n", limits[0], limits[1]);
      } else {
        printf("tRange = %lf %lf\n", limits[0], limits[1]);
      }
    } else if (oclass == FACE) {
      for (i = 0; i < 2*level+2; i++) printf(" ");
      printf("uRange = %lf %lf, vRange = %lf %lf\n", limits[0], limits[1], 
                                                     limits[2], limits[3]);
    }
/*
    if ((geom != NULL) && (mtype != DEGENERATE)) parseOut(level+1, geom, 0);
    if (senses == NULL) {
      for (i = 0; i < nobjs; i++) parseOut(level+1, objs[i], 0);
    } else {
      for (i = 0; i < nobjs; i++) parseOut(level+1, objs[i], senses[i]);
    }
    if ((geom != NULL) && (oclass == LOOP))
      for (i = 0; i < nobjs; i++) parseOut(level+1, objs[i+nobjs], 0);
 */
  }

}


int main(int argc, char *argv[])
{
  int    i, j, nedge, n, stat;
  double data[6] = {0., 0., 0., 1., 1., 1.};
  ego    context, body, ref, *edges, *objs;
  
  if (argc != 1) {
    printf("\n Usage: ref\n\n");
    return 1;
  }

  /* create an EGADS context */
  stat = EG_open(&context);
  if (stat != EGADS_SUCCESS) {
    printf(" EG_open return = %d\n", stat);
    return 1;
  }
  
  /* make a body */
  stat = EG_makeSolidBody(context, BOX, data, &body);
  if (stat != EGADS_SUCCESS) {
    printf(" EG_makeSolidBody return = %d\n", stat);
    return 1;
  }
  
  stat = EG_getBodyTopos(body, NULL, EDGE, &nedge, &edges);
  if (stat != EGADS_SUCCESS) {
    printf(" EG_makeSolidBody return = %d\n", stat);
    return 1;
  }
  
  for (i = 0; i < nedge; i++) {
    printf(" Edge %d Reference Objects:\n", i+1);
    stat = EG_referenceObjects(edges[i], &n, &objs);
    if (stat != EGADS_SUCCESS) {
      printf(" EG_referenceObjects return = %d\n", stat);
      continue;
    }
    stat = EG_getBody(edges[i], &ref);
    if (stat == EGADS_SUCCESS) {
      if (body != ref) printf("  Wrong Body for EDGE %d!\n", i+1);
    } else {
      printf(" Error: EG_getBody EDGE = %d!\n", stat);
    }
    for (j = 0; j < n; j++) {
      parseOut(0, objs[j], 0);
    }
    EG_free(objs);
    printf(" \n");
  }
  EG_free(edges);
 
  printf(" EG_deleteObject body = %d\n", EG_deleteObject(body));
  printf(" EG_close the context = %d\n", EG_close(context));
  return 0;
}
