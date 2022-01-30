#!/usr/bin/python3
"""
	doc
"""
import sys


count_L = 0
data = {"status_code": [],
        "file_size": 0}
try:
	for line in sys.stdin:
		count_L += 1
		data_list = line[:-1].split(" ")[-2:]
		if data_list[0] and data_list[1]:
			data["status_code"].append(data_list[0])
			data["file_size"] += int(data_list[1])
		final_data = {}
		final_data['File size'] = data["file_size"]
		for elem in sorted(data["status_code"]):
			if elem not in final_data.keys():
				final_data[elem] = data["status_code"].count(elem)
		if count_L == 10:
			for key in final_data:
				print(key + ": " , final_data[key])
			count_L = 0
			data = {"status_code": [],
					"file_size": 0}
except:
    for key in final_data:
        print(key + ": " , final_data[key])
