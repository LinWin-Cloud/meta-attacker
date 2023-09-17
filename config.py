import os

def get_language() -> str:
    current_work_dir = os.path.dirname(__file__) 
    f = open(current_work_dir + "/language.txt" , "r")
    return f.read().replace("\n" , "")