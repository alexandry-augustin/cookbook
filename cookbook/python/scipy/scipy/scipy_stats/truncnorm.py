import math
import random
import pickle
import copy
import itertools
from sys import stdout
import os

import numpy as np

import seaborn as sns

import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as patches

import scipy.stats as stats
import pandas as pd

sns.set()
# matplotlib.style.use('ggplot')

def wide_to_long(df, pivot):
    """
        wide-to-long for plotting
    """
    df_long = pd.melt(df, 
                      id_vars=[pivot], 
                      value_vars=[e for e in df.columns if e!=pivot])
    
    return df_long

norm = lambda loc, scale: stats.norm(loc=loc, scale=scale).pdf

def truncnorm(mode, 
              stdev, 
              low_bound, 
              high_bound):
    """
        loc_trunc: location of the truncation
    """
    # absolute clipping
    a = (low_bound - mode) / stdev
    b = (high_bound - mode) / stdev

    f = stats.truncnorm(loc=mode, 
                        scale=stdev, 
                        a=a, 
                        b=b).pdf
    # truncnorm_pdf = loc + sigma*stats.truncnorm(loc=0, scale=1, a=a, b=b).pdf(x)
    
    return f

def to_z_score(conf_level):
    """
        https://stackoverflow.com/questions/20864847/probability-to-z-score-and-vice-versa
    """
    
    assert(conf_level < 1)
    assert(conf_level > 0)
    
    return stats.norm.ppf(1-(1-conf_level)/2)

def to_conf_level(z_score):
    """
        https://stackoverflow.com/questions/20864847/probability-to-z-score-and-vice-versa
    """
    
    return stats.norm.cdf(z_score)


if __name__ == '__main__':

    df = pd.DataFrame()

    mode = 0
    stdev = 3

    z_score = to_z_score(.10)
    # z_score = 2
    low_bound = -999 #-z_score*stdev
    high_bound = z_score*stdev

    df['x'] = np.arange(-10, 10, .05)
    df['y'] = df['x'].apply(lambda v: truncnorm(mode=mode, 
                                                stdev=stdev, 
                                                low_bound=low_bound, 
                                                high_bound=high_bound)(v))


    # plot

    df_long = wide_to_long(df, 'x')

    fig = plt.figure(figsize=(10, 5))
    ax = fig.add_subplot(1, 1, 1)

    ax = sns.lineplot(ax=ax,
                  x='x', 
                  y='value', 
                  hue='variable',
                  data=df_long)

    ax.set_xlim(left=-10, right=10)
    # ax.get_xaxis().set_ticklabels(range(-10, 10))
    from matplotlib.ticker import MaxNLocator
    ax.xaxis.set_major_locator(MaxNLocator(integer=True))

    ax = ax.axvline(x=mode, 
                    lw=2, 
                    color='k', 
                    linestyle=':',
                    alpha=.5)
    plt.show()
