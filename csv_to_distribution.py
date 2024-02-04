import pandas as pd

# Read the CSV file into a DataFrame
df = pd.read_csv("File_100_files.csv")

# Select relevant columns for analysis
selected_columns = ['runs.batsman', 'wicket.kind', 'extras.wides', 'extras.legbyes', 'extras.byes', 'extras.noballs', 'extras.penalty', 'runs.non_boundary']

# Filter out innings, over, and ball information
delivery_data = df[selected_columns]

# Display the distribution of different outcomes in each delivery
outcome_distribution = pd.DataFrame()

for column in delivery_data.columns:
    if delivery_data[column].dtype == 'object':
        # For string columns, convert to string before counting
        print(delivery_data[column].astype(str).value_counts())
        outcome_distribution[column] = delivery_data[column].astype(str).value_counts()
    else:
        # For numeric columns, directly count values
        print(delivery_data[column].value_counts(dropna=False))

        outcome_distribution[column] = delivery_data[column].value_counts(dropna=False)

print(outcome_distribution)
