const getPhoneNumber = async (country, phoneNUmber) => {
    const resp = await fetch(`https://jsonmock.hackerrank.com/api/countries?name=${country}`)
    const resp_json = await resp.json()
    if (resp_json.data.length == 0) {
        return "-1"
    }
    const callingCode = resp_json.data[0].callingCodes[resp_json.data[0].callingCodes.length - 1]
    return `+${callingCode} ${phoneNUmber}`
}

getPhoneNumber("Afghanistan", "1234567890").then(console.log)