import requests
import json

def get_country_calling_code(country, phone_number):
    url = f"https://jsonmock.hackerrank.com/api/countries?name={country}"
    response = requests.get(url)
    
    if response.status_code == 200:
        data = json.loads(response.text)["data"]
        
        if not data:
            return "-1"
        
        # Assuming there is only one country object in the array, and using the calling code at the highest index
        callingCodes = data[0]["callingCodes"]
        highest_index_calling_code = callingCodes[-1] if callingCodes else "-1"
        
        return f"+{highest_index_calling_code} {phone_number}"
    else:
        return f"Error: {response.status_code}"

# Example usage
country = "United States"
phone_number = "765355443"
result = get_country_calling_code(country, phone_number)
print(result)
