def list_of_name()-> list[str]: 
    return ["Http Server Attacks" , "Custom Tcp Attacks" , "Ping of Death"]

def get_options(attack_payload: str) -> list[str]:
    attack_payload = attack_payload.replace(" ","_")
