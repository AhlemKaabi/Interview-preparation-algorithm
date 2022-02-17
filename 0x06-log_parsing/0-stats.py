#!/usr/bin/python3
"""
	doc
"""
import sys


if __name__ == '__main__':
	count_L = 0
	data = {"status_code": [],
			"file_size": 0}
	try:
		for line in sys.stdin:
			count_L += 1
			data_list = line.split(" ")[-2:]
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
					if key == '0':
						continue
					print(key + ":" , final_data[key])
				count_L = 0
				# data = {"status_code": [],
				# 		"file_size": 0}
	except Exception:
		pass
	finally:
		for key in final_data:
			print(key + ":" , final_data[key])
