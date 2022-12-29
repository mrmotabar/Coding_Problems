def fruits(fruit_list):
    result = {}
    for fruit in fruit_list:
        if fruit["shape"] == "sphere":
            if 300 <= fruit["mass"] <= 600:
                if 100 <= fruit["volume"] <= 500:
                    if fruit["name"] in result.keys():
                        result[fruit["name"]] += 1
                    else:
                        result[fruit["name"]] = 1
    return result
