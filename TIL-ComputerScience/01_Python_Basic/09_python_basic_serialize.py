# Serialization : Transfrom object into continuous data
# serialization of object is needed for to save on computer

# pickle module is used on python to serialize objects
# json module serialize object into string
import pickle
import json

with open('test.txt','wb') as f:
    print(pickle.dump([1, 2, 3, 4, 5], f))

print(pickle.dumps([1, 2, 3, 4]))
print(pickle.loads(b'\x80\x04\x95\r\x00\x00\x00\x00\x00\x00\x00]\x94(K\x01K\x02K\x03K\x04e.'))

print(json.dumps({"a": "b", "c": "d"}))
print(json.loads('{"a": "b", "c": "d"}'))