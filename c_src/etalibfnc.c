// This file is part of ETALIB released under the MIT license.
// See the LICENSE file for more information.

#include <ta_libc.h>
#include "etalibfnc.h"
#include "util.h"

ERL_NIF_TERM
ta_var(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // declare the variables
    EtaStruct eta;
    EtaStruct* e = &eta;

    if(init_function_input_params(env, argc, argv, e)==1)
    {// something wrong with input arguments, clean up and return bad argument error
        eta_destroy(e);
        return enif_make_badarg(env);
    }
    
    // extract option values
    e->optInTimePeriod = (int)extract_option(env, argv[1], "timeperiod", 2);
    double optInNbDev = extract_option(env, argv[1], "nbdev", 2);
   
    // call TA-Lib function
    TA_RetCode retCode = TA_VAR( 
        e->startIdx,
        e->endIdx,
        e->inValues0,
        e->optInTimePeriod, 
        optInNbDev,
        &e->outBegIdx,
        &e->outNBElement,
        &e->outDblValues0[0]
    );

    // generate results
    ERL_NIF_TERM results = eta_generate_results_double(e, retCode, e->outDblValues0);

    // clean up
    eta_destroy(e);

    // return the results;
    return results;   
}

ERL_NIF_TERM
ta_sma(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_SMA);
}

ERL_NIF_TERM
ta_rsi(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_RSI);
}

ERL_NIF_TERM
ta_wma(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_WMA);
}


ERL_NIF_TERM
ta_acos(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_ACOS);
}


ERL_NIF_TERM
ta_asin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_ASIN);
}


ERL_NIF_TERM
ta_atan(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_ATAN);
}


ERL_NIF_TERM
ta_cmo(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_CMO);
}


ERL_NIF_TERM
ta_dema(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_DEMA);
}


ERL_NIF_TERM
ta_ema(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_EMA);
}


ERL_NIF_TERM
ta_ceil(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_CEIL);
}

ERL_NIF_TERM
ta_cos(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_COS);
}

ERL_NIF_TERM
ta_cosh(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_COSH);
}

ERL_NIF_TERM
ta_exp(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_EXP);
}

ERL_NIF_TERM
ta_floor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_FLOOR);
}

ERL_NIF_TERM
ta_ht_dcperiod(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_HT_DCPERIOD);
}

ERL_NIF_TERM
ta_ht_dcphase(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_HT_DCPHASE);
}

ERL_NIF_TERM
ta_ht_trendline(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_HT_TRENDLINE);
}

ERL_NIF_TERM
ta_ht_ln(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_LN);
}

ERL_NIF_TERM
ta_ht_log10(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_LOG10);
}


ERL_NIF_TERM
ta_kama(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_KAMA);
}


ERL_NIF_TERM
ta_linearreg(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_LINEARREG);
}


ERL_NIF_TERM
ta_linearreg_angle(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_LINEARREG_ANGLE);
}


ERL_NIF_TERM
ta_linearreg_intercept(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_LINEARREG_INTERCEPT);
}

ERL_NIF_TERM
ta_linearreg_slope(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_LINEARREG_SLOPE);
}

ERL_NIF_TERM
ta_max(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_MAX);
}

ERL_NIF_TERM
ta_min(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_MIN);
}

ERL_NIF_TERM
ta_midpoint(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_MIDPOINT);
}

ERL_NIF_TERM
ta_mom(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_MOM);
}

ERL_NIF_TERM
ta_roc(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_ROC);
}

ERL_NIF_TERM
ta_rocp(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_ROCP);
}

ERL_NIF_TERM
ta_rocr(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_ROCR);
}

ERL_NIF_TERM
ta_rocr100(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_ROCR100);
}

ERL_NIF_TERM
ta_tema(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_TEMA);
}

ERL_NIF_TERM
ta_trima(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_TRIMA);
}

ERL_NIF_TERM
ta_trix(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_TRIX);
}

ERL_NIF_TERM
ta_tsf(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_TSF);
}

ERL_NIF_TERM
ta_sum(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument(env, argc, argv, "timeperiod", &TA_SUM);
}

ERL_NIF_TERM
ta_sin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_SIN);
}

ERL_NIF_TERM
ta_sinh(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_SINH);
}

ERL_NIF_TERM
ta_sqrt(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_SQRT);
}

ERL_NIF_TERM
ta_tan(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_TAN);
}

ERL_NIF_TERM
ta_tanh(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array(env, argc, argv, &TA_TANH);
}

ERL_NIF_TERM
ta_adx(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_ADX);
}

ERL_NIF_TERM
ta_adxr(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_ADXR);
}

ERL_NIF_TERM
ta_atr(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_ATR);
}

ERL_NIF_TERM
ta_cci(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_CCI);
}

ERL_NIF_TERM
ta_dx(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_DX);
}

ERL_NIF_TERM
ta_minus_di(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_MINUS_DI);
}

ERL_NIF_TERM
ta_natr(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_NATR);
}

ERL_NIF_TERM
ta_plus_di(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_PLUS_DI);
}

ERL_NIF_TERM
ta_willr(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays_and_one_argument(env, argc, argv, "timeperiod", &TA_WILLR);
}

ERL_NIF_TERM
ta_cdl2crows(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL2CROWS);
}

ERL_NIF_TERM
ta_cdl3blackcrows(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3BLACKCROWS);
}

ERL_NIF_TERM
ta_cdl3inside(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3INSIDE);
}

ERL_NIF_TERM
ta_cdl3linestrike(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3LINESTRIKE);
}

ERL_NIF_TERM
ta_cdl3outside(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3OUTSIDE);
}

ERL_NIF_TERM
ta_cdl3starsinsouth(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3STARSINSOUTH);
}

ERL_NIF_TERM
ta_cdl3whitesoldiers(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDL3WHITESOLDIERS);
}

ERL_NIF_TERM
ta_cdladvanceblock(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLADVANCEBLOCK);
}

ERL_NIF_TERM
ta_cdlbelthold(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLBELTHOLD);
}

ERL_NIF_TERM
ta_cdlbreakaway(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLBREAKAWAY);
}

ERL_NIF_TERM
ta_cdlclosingmarubozu(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLCLOSINGMARUBOZU);
}

ERL_NIF_TERM
ta_cdlconcealbabyswall(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLCONCEALBABYSWALL);
}

ERL_NIF_TERM
ta_cdlcounterattack(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLCOUNTERATTACK);
}

ERL_NIF_TERM
ta_cdldoji(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLDOJI);
}

ERL_NIF_TERM
ta_cdldojistar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLDOJISTAR);
}

ERL_NIF_TERM
ta_cdldragonflydoji(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLDRAGONFLYDOJI);
}

ERL_NIF_TERM
ta_cdlengulfing(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLENGULFING);
}

ERL_NIF_TERM
ta_cdlgapsidesidewhite(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLGAPSIDESIDEWHITE);
}

ERL_NIF_TERM
ta_cdlgravestonedoji(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLGRAVESTONEDOJI);
}

ERL_NIF_TERM
ta_cdlhammer(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHAMMER);
}

ERL_NIF_TERM
ta_cdlhangingman(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHANGINGMAN);
}

ERL_NIF_TERM
ta_cdlharami(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHARAMI);
}

ERL_NIF_TERM
ta_cdlharamicross(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHARAMICROSS);
}

ERL_NIF_TERM
ta_cdlhighwave(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHIGHWAVE);
}

ERL_NIF_TERM
ta_cdlhikkake(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHIKKAKE);
}

ERL_NIF_TERM
ta_cdlhikkakemod(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHIKKAKEMOD);
}

ERL_NIF_TERM
ta_cdlhomingpigeon(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLHOMINGPIGEON);
}

ERL_NIF_TERM
ta_cdlidentical3crows(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLIDENTICAL3CROWS);
}

ERL_NIF_TERM
ta_cdlinneck(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLINNECK);
}

ERL_NIF_TERM
ta_cdlinvertedhammer(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLINVERTEDHAMMER);
}

ERL_NIF_TERM
ta_cdlkicking(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLKICKING);
}

ERL_NIF_TERM
ta_cdlkickingbylength(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLKICKINGBYLENGTH);
}

ERL_NIF_TERM
ta_cdlladderbottom(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLLADDERBOTTOM);
}

ERL_NIF_TERM
ta_cdllongleggeddoji(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLLONGLEGGEDDOJI);
}

ERL_NIF_TERM
ta_cdllongline(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLLONGLINE);
}

ERL_NIF_TERM
ta_cdlmarubozu(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLMARUBOZU);
}

ERL_NIF_TERM
ta_cdlmatchinglow(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLMATCHINGLOW);
}

ERL_NIF_TERM
ta_cdlonneck(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLONNECK);
}

ERL_NIF_TERM
ta_cdlpiercing(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLPIERCING);
}

ERL_NIF_TERM
ta_cdlrickshawman(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLRICKSHAWMAN);
}

ERL_NIF_TERM
ta_cdlrisefall3methods(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLRISEFALL3METHODS);
}

ERL_NIF_TERM
ta_cdlseparatinglines(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSEPARATINGLINES);
}

ERL_NIF_TERM
ta_cdlshootingstar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSHOOTINGSTAR);
}

ERL_NIF_TERM
ta_cdlshortline(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSHORTLINE);
}

ERL_NIF_TERM
ta_cdlspinningtop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSPINNINGTOP);
}

ERL_NIF_TERM
ta_cdlstalledpattern(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSTALLEDPATTERN);
}

ERL_NIF_TERM
ta_cdlsticksandwich(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLSTICKSANDWICH);
}

ERL_NIF_TERM
ta_cdltakuri(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLTAKURI);
}

ERL_NIF_TERM
ta_cdltasukigap(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLTASUKIGAP);
}

ERL_NIF_TERM
ta_cdlthrusting(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLTHRUSTING);
}

ERL_NIF_TERM
ta_cdltristar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLTRISTAR);
}

ERL_NIF_TERM
ta_cdlunique3river(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLUNIQUE3RIVER);
}

ERL_NIF_TERM
ta_cdlupsidegap2crows(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLUPSIDEGAP2CROWS);
}

ERL_NIF_TERM
ta_cdlxsidegap3methods(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays(env, argc, argv, &TA_CDLXSIDEGAP3METHODS);
}

ERL_NIF_TERM
ta_cdlabandonedbaby(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLABANDONEDBABY);
}

ERL_NIF_TERM
ta_cdldarkcloudcover(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLDARKCLOUDCOVER);
}

ERL_NIF_TERM
ta_cdleveningdojistar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLEVENINGDOJISTAR);
}

ERL_NIF_TERM
ta_cdleveningstar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLEVENINGSTAR);
}

ERL_NIF_TERM
ta_cdlmathold(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLMATHOLD);
}

ERL_NIF_TERM
ta_cdlmorningdojistar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLMORNINGDOJISTAR);
}

ERL_NIF_TERM
ta_cdlmorningstar(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_and_one_argument(env, argc, argv, "penetration", &TA_CDLMORNINGSTAR);
}

ERL_NIF_TERM
ta_bop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_out_double(env, argc, argv, &TA_BOP);
}

ERL_NIF_TERM
ta_avgprice(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_out_double(env, argc, argv, &TA_AVGPRICE);
}

ERL_NIF_TERM
ta_ad(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_four_in_arrays_out_double(env, argc, argv, &TA_AD);
}

ERL_NIF_TERM
ta_aroonosc(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_AROONOSC);
}

ERL_NIF_TERM
ta_beta(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_BETA);
}

ERL_NIF_TERM
ta_correl(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_CORREL);
}

ERL_NIF_TERM
ta_minus_dm(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_MINUS_DM);
}

ERL_NIF_TERM
ta_plus_dm(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_PLUS_DM);
}

ERL_NIF_TERM
ta_midprice(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array_and_one_argument(env, argc, argv, "high", "low", "timeperiod", &TA_MIDPRICE);
}

ERL_NIF_TERM
ta_mult(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "high", "low", &TA_MULT);
}

ERL_NIF_TERM
ta_add(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "high", "low", &TA_ADD);
}

ERL_NIF_TERM
ta_sub(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "high", "low", &TA_SUB);
}

ERL_NIF_TERM
ta_div(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "high", "low", &TA_DIV);
}

ERL_NIF_TERM
ta_obv(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "close", "volume", &TA_OBV);
}

ERL_NIF_TERM
ta_medprice(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_two_in_array(env, argc, argv, "high", "low", &TA_MEDPRICE);
}

ERL_NIF_TERM
ta_trange(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays(env, argc, argv, &TA_TRANGE);
}

ERL_NIF_TERM
ta_typprice(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays(env, argc, argv, &TA_TYPPRICE);
}

ERL_NIF_TERM
ta_wclprice(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_three_in_arrays(env, argc, argv, &TA_WCLPRICE);
}

ERL_NIF_TERM
ta_maxindex(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument_int_out(env, argc, argv, "timeperiod", &TA_MAXINDEX);
}

ERL_NIF_TERM
ta_minindex(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    // call TA-Lib Function
    return call_function_with_one_in_array_and_one_argument_int_out(env, argc, argv, "timeperiod", &TA_MININDEX);
}
