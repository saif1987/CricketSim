import os
import yaml
import csv
import pandas as pd
import numpy as np
from enum import Enum

class WicketKind(Enum):
    BOWLED = 'bowled'
    CAUGHT = 'caught'
    CAUGHT_AND_BOWLED = 'caught and bowled'
    LBW = 'lbw'
    STUMPED = 'stumped'
    RUN_OUT = 'run out'
    RETIRED_HURT = 'retired hurt'
    HIT_WICKET = 'hit wicket'
    OBSTRUCTING_THE_FIELD = 'obstructing the field'
    HIT_THE_BALL_TWICE = 'hit the ball twice'
    HANDLED_THE_BALL = 'handled the ball'
    TIMED_OUT = 'timed out'

def convert_yaml_to_df(yaml_file, csv_file):
    with open(yaml_file, 'r') as yaml_file:
        data = yaml.safe_load(yaml_file)

    if data['info']['gender'] == 'female':
        return

    print(data['meta'])
    deliveries = []

    for innings in data['innings']:
        n_inn = 0 if '1st innings' in innings else 1

        for inning in innings.values():

            for over_data in inning['deliveries']:
                for delivery_number, delivery_data in over_data.items():
                     # deliveries.append({delivery_key: delivery_data})


                    row_data = {'innings': n_inn, 'over': int(np.floor(delivery_number)), 'ball': int(np.mod(delivery_number * 10, 10))}
                    row_data.update(delivery_data)
                    deliveries.append(row_data)
        # Assuming data is a list of dictionaries
        # keys = data[0].keys()
    df = pd.json_normalize(deliveries)
        # df['wicket_kind'] = df['wicket.kind'].apply(lambda x: getattr(WicketKind, str(x).upper(), None))

        # print(df)

    df= df.drop(columns=['non_striker','bowler','batsman','runs.extras','runs.total','wicket.player_out','wicket.fielders'])
    print(df.columns)
    return df
        # df.to_csv(csv_file_path, mode='a',header=False, index=False)


sourcefilepath = '/home/md/Downloads/odis/odis/'
df_list = []
maxx=10
# Loop through all files in the specified directory
for filename in os.listdir(sourcefilepath):
    if maxx>0:
        maxx=maxx-1
    else:
        break
    if filename.endswith('.yaml'):
        yaml_file_path = os.path.join(sourcefilepath, filename)
        print(yaml_file_path)
        csv_file_path = os.path.join(sourcefilepath, filename[:-5] + '.csv')
        df = convert_yaml_to_df(yaml_file_path, csv_file_path)
        
        df_list.append(df)

# Concatenate all DataFrames in the list into a single DataFrame
df_combined = pd.concat(df_list, ignore_index=True)
df_combined.to_csv( os.path.join('test10files.csv'), index=False)
