import os
import sys
import json


if __name__ == "__main__":
    arg = sys.argv
    #print(len(arg))
    if len(arg) == 1:
        import list_en
        for i in list_en.list_of_name():
            print(" - "+ i)