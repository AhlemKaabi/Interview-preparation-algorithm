#!/usr/bin/python3
"""
    Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
        Return True if ALL boxes can be opened, else return False.
    """
    unlocked_boxes_index = [0]

    for idx in range(len(boxes)):
        if idx in unlocked_boxes_index:
            for j in boxes[idx]:
                unlocked_boxes_index.append(j)
                if j < len(boxes):
                    if boxes[j] != [] and type(boxes[j]) == list:
                        unlocked_boxes_index.extend(boxes[j])
                    if boxes[j] == None:
                        return False
                    if type(boxes[j]) == int:
                        unlocked_boxes_index.append(boxes[j])
        else:
            return False
    return True
