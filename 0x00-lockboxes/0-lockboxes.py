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
			for j in range(len(boxes[idx])):
				if boxes[idx][j] not in unlocked_boxes_index:
					unlocked_boxes_index.append(boxes[idx][j])
					for h in range(len(boxes[boxes[idx][j]])):
						if boxes[boxes[idx][j]][h] not in unlocked_boxes_index:
							unlocked_boxes_index.append(boxes[boxes[idx][j]][h])
		else:
			return False
	return True