# https://stackoverflow.com/questions/50239878/pandas-dataframe-column-numerical-integration

from scipy import integrate

df.groupby(df.Device).apply(lambda g: integrate.trapz(g.Current, x=g.TimeSec))

