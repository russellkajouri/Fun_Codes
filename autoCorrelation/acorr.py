# -------------------------------------------------------------------
#
# @author : Kajo
# @email  : rasoulkajouri@gmail.com
# 
# @last modified : 14 Jan 2021
#
# -------------------------------------------------------------------

def acorr(arr):
    import math
    # -------------------------------------------
    # to find the average of the array

    ave_arr = (sum(arr) / len(arr))

    # -------------------------------------------
    # to find the correlate values

    variance_arr = 0
    for n in range(len(arr)):
        variance_arr += (arr[n] - ave_arr) * (arr[n] - ave_arr)

    # -------------------------------------------
    # number of lags

    numLags = len(arr)

    # -------------------------------------------
    # left and right wings

    lWing = [0] * (len(arr) - 1)
    rWing = [0] * len(arr)

    # -------------------------------------------
    # to find the auto correlation on left wing

    for lag in range(numLags):
        numerator = 0.0
        for n in range(len(arr) - lag):
            numerator += (arr[n] - ave_arr) * (arr[n+lag] - ave_arr)
        rWing[lag] = numerator / variance_arr
        pass
    for lag in range(1, numLags):
        numerator = 0.0
        for n in range(len(arr)-1,lag-1,-1):
            numerator += (arr[n] - ave_arr) * (arr[n-lag] - ave_arr)
        lWing[lag-1] = numerator / variance_arr
        pass

    lWing = list(reversed(lWing))
    return lWing + rWing
