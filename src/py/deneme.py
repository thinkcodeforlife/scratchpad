# !usr/bin/python
# -*- character-encoding = utf-8 -*-
"""
	Documentation
	----------------
	This is just great
"""
__author__ = "thinkcodeforlife"
__license__ = "mit"
__maintainer__ = "adoerdo"


### ========= Imports ============== 
import sys
import os
import datetime
import re
import random
import math

### ========= Functions ============== 
def main():
	"""This is a test"""
	# pattern = r"(?=[0-9]*)^[A-Z]{1}[a-z]{2,10}$"
	# pattern = r"^[0-9]*[A-Z]{1}[a-z]{2,10}$"
	pattern = r"(?=[0-9]*)(?:.*)([A-Z]{1}[a-z]{2,10})$"
	print("pattern:", pattern)
	print("Please enter some")
	input_string = input()
	print("You input:", input_string)
	matched = re.match(pattern, input_string)
	search = re.search(pattern, input_string)
	print("search.group(1):", search.group(1))
	print("search:", search)
	if matched is None:
		print("matched", matched)
		exit()
	group_0 = matched.group(0)
	print("Group 0:", group_0)

if __name__ == '__main__':
	main()

### ========= End of file ============== 