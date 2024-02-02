import yaml
import csv

def convert_yaml_to_csv(yaml_file, csv_file):
    with open(yaml_file, 'r') as yaml_file:
        data = yaml.safe_load(yaml_file)

    # Assuming data is a list of dictionaries
    keys = data[0].keys()

    with open(csv_file, 'w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=keys)
        writer.writeheader()
        writer.writerows(data)

# Example usage
yaml_file_path = 'example.yaml'
csv_file_path = 'output.csv'

convert_yaml_to_csv(yaml_file_path, csv_file_path)