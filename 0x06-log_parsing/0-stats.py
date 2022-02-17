#!/usr/bin/python3
"""
    doc
"""
import sys


if __name__ == '__main__':
    codes = ["200", "301", "400", "401", "403", "405", "404", "500"]
    count_L = 0
    data = {"status_code": [],
            "file_size": 0}
    final_data = {}
    try:
        for line in sys.stdin:
            if "GET /projects/260 HTTP/1.1" in line:
                count_L += 1
                data_list = line.split(" ")[-2:]
                if data_list[0] and data_list[1]:
                    if data_list[0] in codes:
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
        if not final_data:
            print("File size:" , data["file_size"])
        for key in final_data:
            print(key + ":" , final_data[key])
