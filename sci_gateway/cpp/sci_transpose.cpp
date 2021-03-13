extern "C" {
#include<Scierror.h>
#include<api_scilab.h>
#include <stdio.h>
#include "localization.h"
#include "trans.h"

static const char *fname = "transpose";

int sci_transpose(
                    scilabEnv
                    env, int nin,
                    scilabVar
                    *in, int nopt,
                    scilabOpt
                    opt, int nout,
                    scilabVar
                    *out)
{
    if (nin != 1)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 2);
        return 1;
    }

    if (nout != 1)
    {
        Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
        return 1;
    }
    if (scilab_isMatrix2d(env, in[1]) != 0) {
         Scierror(999, _("%s: Wrong type for input argument #%d: A matrix expected.\n"), fname, 1);
        return 1;
    }
    int m, n;
    int size1 = scilab_getDim2d(env, in[0], &m, &n);
    out[0] = scilab_createDoubleMatrix2d(env, n, m, 0);
    double *mat = NULL;
    double *out1 = NULL;
    scilab_getDoubleArray(env, in[0], &mat);
    scilab_getDoubleArray(env, out[0], &out1);
    int i, j;

    double **a = (double **) malloc(m*sizeof(double*));
    for(i = 0; i < m; i++) {
        a[i] = (double *)malloc(n*sizeof(double));
    }

    int c = 0;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = mat[c++];
        }
    }

    double **ret = trans(a, m, n);
    c=0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            out1[c++] = ret[i][j];
        }
    }
    return 0;
}


}