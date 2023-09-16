import os
import sys
import json
import list_en

if __name__ == "__main__":
    arg = sys.argv
    #print(len(arg))
    if len(arg) == 1:

        base_print = [
            " -version        Show Version Information.",
            "\n @ALL THE ATTACK CONTENT"
        ]
        for i in base_print:
            print(i)

        for i in list_en.list_of_name():
            print(" - "+ i + " ")
            for j in list_en.get_options(i):
                print("     [" + j + "] ")
            print("     *For Example: \n          "+list_en.get_for_example(i))
    else:
        