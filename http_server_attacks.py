import requests
import threading

def _attack(url , data) -> None:
    print(str(url)+" "+str(data))

def run(url: str , concurrent: int , data: int) -> None:
    t = threading.Thread(target=_attack , args=(url , data))
    t.start()