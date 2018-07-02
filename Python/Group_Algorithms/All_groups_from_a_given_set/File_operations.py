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

def read_from_file(file_name, number):
    file = open(file_name, "r")
    if (number != '*'):
        data = file.read(number)
    else:
         data = file.read()
    return data
    
def append_to_file(file_name,data):
    temp_data =  read_from_file(file_name)
    file.close()
    file = open(file_name, "w")
    file.write(str(temp_data))
    file.write(str(data))
    file.close

def list_from_file(file_name,element):
    raw_data =  read_from_file(file_name,'*')
    data = raw_data.split(element)
    return data
