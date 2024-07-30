import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

sns.set()

# https://stackoverflow.com/questions/68616781/customizing-the-hue-colors-used-in-seaborn-barplot

if __name__ == '__main__':

    df = pd.DataFrame({'Early': {'A': 686, 'B': 533, 'C': 833, 'D': 625, 'E': 820},
     'Long Overdue': {'A': 203, 'B': 237, 'C': 436, 'D': 458, 'E': 408},
     'On Time': {'A': 881, 'B': 903, 'C': 100, 'D': 53, 'E': 50},
     'Overdue': {'A': 412, 'B': 509, 'C': 813, 'D': 1046, 'E': 904}})

    df_long = df.unstack().to_frame(name='value')
    df_long = df_long.swaplevel()
    df_long.reset_index(inplace=True)
    df_long.columns = ['group', 'status', 'value']
    df_long['status'] = pd.Categorical(df_long['status'], ["Early", "On Time", "Overdue", "Long Overdue"])
    df_long = df_long.sort_values("status")

    status = df_long['status'].unique()
    palette = sns.color_palette('deep', len(status))
    palette = dict(zip(status, palette))

    # palette = {
    #     'Early': 'tab:blue',
    #     'On Time': 'tab:green',
    #     'Overdue': 'tab:orange',
    #     'Long Overdue': 'tab:red',
    # }

    fig, ax = plt.subplots(figsize=(18.5, 10.5))

    g = sns.barplot(data=df_long, 
                    x='group', 
                    y='value', 
                    hue='status', 
                    palette=palette, 
                    ax=ax)

    for bar in g.patches:
        height = bar.get_height()
        ax.text(bar.get_x() + bar.get_width() / 2., 0.5 * height, int(height),
                    ha='center', va='center', color='white')
    plt.xticks(fontsize=12)
    plt.legend(loc='upper left', prop={'size': 14})

    ax.xaxis.label.set_visible(False)
    ax.axes.get_yaxis().set_visible(False)

    plt.show()
