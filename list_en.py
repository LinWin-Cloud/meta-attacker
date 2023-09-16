
lists: str = [
    "Http Server Attacks" ,
    "Custom Tcp Attacks" , 
    "Ping of Death"
]

a_1 = [
    "Url",
    "Concurrent",
    "Total data volume"
]

a_2 = [
    "IP",
    "Port",
    "Cocurrent",
    "Total data volume"
]

a_3 = [
    "Url",
    "Cocurrent",
    "Total data volume"
]

b_1 = "python3 metaattack.py -1 https://www.bing.com/ 1000 100000"
b_2 = "python3 metaattack.py -2 127.0.0.1 80 1000 100000"
b_3 = "python3 metaattack.py -3 www.bing.com 1000 100000"

def get_for_example(attack_payload: str) -> str:
    if attack_payload == lists[0]:
        return b_1
    if attack_payload == lists[1]:
        return b_2
    if attack_payload == lists[2]:
        return b_3
    else:
        return None

def list_of_name()-> list[str]: 
    return lists

def get_options(attack_payload: str) -> list[str]:
    if attack_payload == lists[0]:
        return a_1
    if attack_payload == lists[1]:
        return a_2
    if attack_payload == lists[2]:
        return a_3
    else:
        return None