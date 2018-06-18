def dict_from_file(file_name):
    data = dict()
    raw_data = open(file_name,"r")
    for item in raw_data:
        if ':' in item:
            key,value = item.split(':', 1)
            data[key]=value.rstrip()
    return data

def write_to_file(file_name,data):
    file = open(file_name, "w")
    file.write(str(data))
    file.close

def append_to_file(file_name,data):
    file = open(file_name, "r")
    temp_data = file.read()
    file.close()
    file = open(file_name, "w")
    file.write(str(temp_data))
    file.write(str(data))
    file.close
