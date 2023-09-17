import os
import sys
import json
import list_en
import list_zh
import config

def print_english_information() -> None:
    for i in list_en.list_of_name():
        print(" - "+ i + " ")
        for j in list_en.get_options(i):
            print("     [" + j + "] ")
        print("     *For Example: \n          "+list_en.get_for_example(i))

def print_chinese_information() -> None:
    for i in list_zh.list_of_name():
        print(" - "+ i + " ")
        for j in list_zh.get_options(i):
            print("     [" + j + "] ")
        print("     *例如: \n          "+list_zh.get_for_example(i))

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

        if config.get_language() == "english":
            print_english_information()
        else:
            print_chinese_information()
    else:
        try:
            options: int = int(arg[1])
            if options == 1:
                pass
            if options == 2:
                pass
            if options == 3:
                pass
            else:
                print(" [ERR] Private options error.")
        except:
            print(" [ERR] Private options error.")
            exit(1)