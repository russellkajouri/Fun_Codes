# -------------------------------------------------------------------
#
# @author : Kajo
# @email  : rasoulkajouri@gmail.com
#
# @last modified : 14 Jan 2021
#
# -------------------------------------------------------------------

# -------------------------------------------------------------------
# to find the average of the array
def Average(arr):
	return sum(arr)/len(arr)
# end of the average function
# -------------------------------------------------------------------

# -------------------------------------------------------------------
# to find the variance of the array
def Variance(arr):
	ave = Average(arr)
	var = 0.0
	for n in range(len(arr)):
		var += (arr[n]-ave)*(arr[n]-ave)
	return var
# end of the variance function
# -------------------------------------------------------------------
# to find the autocorrelation series under the full mode
def FullAcorr(arr, ave_arr, variance_arr):
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
# the end of the FullAcorr function
# -------------------------------------------------------------------

# -------------------------------------------------------------------
# to find the autocorrelation series under the same mode
def SameAcorr(arr, ave_arr, variance_arr):
	# -------------------------------------------
	# number of lags
    numLags = len(arr)

    # -------------------------------------------
    # left and right wings

    rWing = [0] * len(arr)

    # -------------------------------------------
    # to find the auto correlation on left wing

    for lag in range(numLags):
        numerator = 0.0
        for n in range(len(arr) - lag):
            numerator += (arr[n] - ave_arr) * (arr[n+lag] - ave_arr)
        rWing[lag] = numerator / variance_arr
        pass
    return rWing
# the end of the FullAcorr function
# -------------------------------------------------------------------
# -------------------------------------------------------------------
def Acorr(arr, mode="same"):
	import math
# -------------------------------------------
# to find the variance

	average = Average(arr)
	variance = Variance(arr)

# -------------------------------------------
# to recognize the mode

	FULL = "full"
	SAME = "same"

# -------------------------------------------
# to calculate the auto correlation 

	if mode == FULL:
		return FullAcorr(arr, average, variance)
	elif mode == SAME:
		return SameAcorr(arr, average, variance)
	else:
		return []
# the end of the acorr function
# -------------------------------------------------------------------
