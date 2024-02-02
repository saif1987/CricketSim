import yaml
import csv
import pandas as pd
import numpy as np


def convert_yaml_to_csv(yaml_file, csv_file):
    with open(yaml_file, 'r') as yaml_file:
        data = yaml.safe_load(yaml_file)

    for innings in data['innings']:
        deliveries = []
        for inning in innings.values():
            for over_data in inning['deliveries']:
                for delivery_number, delivery_data in over_data.items():
                     # deliveries.append({delivery_key: delivery_data})

                    row_data = {'over': np.floor(delivery_number), 'ball':np.mod(delivery_number*10,10)}
                    row_data.update(delivery_data)
                    deliveries.append(row_data)
        # Assuming data is a list of dictionaries
        # keys = data[0].keys()
        df = pd.json_normalize(deliveries)
        print(df)
    
    with open(csv_file, 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=keys)
        writer.writeheader()
        writer.writerows(data)

# Example usage
sourcefilepath= '/home/md/Downloads/odis/odis/'
filename = '1406078'
yaml_file_path = sourcefilepath + filename +'.yaml'
csv_file_path = filename + '.csv'

convert_yaml_to_csv(yaml_file_path, csv_file_path)