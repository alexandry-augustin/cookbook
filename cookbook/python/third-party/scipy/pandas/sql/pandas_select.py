"""
	http://pandas.pydata.org/pandas-docs/stable/comparison_with_sql.html
"""

import pandas as pd

if __name__ == '__main__':

	url = 'https://raw.github.com/pydata/pandas/master/pandas/tests/data/tips.csv'
	tips = pd.read_csv(url)
	#--------------------------------------------------
#	SELECT *
#	FROM tips
#	LIMIT 5;
	print tips.head()
	#--------------------------------------------------
#	SELECT total_bill, tip, smoker, time
#	FROM tips
#	LIMIT 5;
#	print tips[['total_bill', 'tip', 'smoker', 'time']].head(5)
	#--------------------------------------------------
#	SELECT *
#	FROM tips
#	WHERE time = 'Dinner'
#	LIMIT 5;
#	print tips[tips['time'] == 'Dinner'].head(5)
	#--------------------------------------------------
#	-- tips of more than $5.00 at Dinner meals
#	SELECT *
#	FROM tips
#	WHERE time = 'Dinner' AND tip > 5.00;
#	print tips[(tips['time'] == 'Dinner') & (tips['tip'] > 5.00)]
	#--------------------------------------------------
#	-- tips by parties of at least 5 diners OR bill total was more than $45
#	SELECT *
#	FROM tips
#	WHERE size >= 5 OR total_bill > 45;
#	print tips[(tips['size'] >= 5) | (tips['total_bill'] > 45)]
	#--------------------------------------------------
#	SELECT sex, count(*)
#	FROM tips
#	GROUP BY sex;
	print tips.groupby('sex').size()
	print tips.groupby('sex')['total_bill'].count()
