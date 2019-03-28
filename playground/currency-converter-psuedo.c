/* 
Your previous C content is preserved below:

/*
Define a class representing a currency converter.

Currency exchange are from a super expensive external service.
All call to this exchange are call through their api.  Assume
api.get_exchange_rate(A, B) will return the current value to
exchange A to B.

All exchange rate are valid for 1 minute

Define the datastructure you'll use to store the data.

You are only require to implement the process_request function
and the Update_exechange_rate function.

Optimize the call to the external service.  The less calls the better.
Optimize the storage used.
  
*/
  

queue<RequestObject> reqs;
// Example request - <300, CURR_INR, CURR_USD> - inr to usd
  
#define NUM_CURRENCIES sizeof(__CURRENCIES__)/sizeof(int)

class CurrencyConverter {
  
  char* base_curr; // CURR_INR
  
  map<char*, long> last_updated; // stores the last updated
  // time of that currency conv rate
  
  map<char*, float> exch_rate;
    
  public:
  
  CurrencyConverter(char* base_curr) : base_curr(base_curr) {}
    
  void process_requests(queue<RequestObject> q) {
      RequestObject curr_request = q.front();
      q.pop();
      
      char* from_curr = curr_request.from(),
          to_curr   = curr_request.to(),
          amt       = curr_request.amt();
    
      long now = to_seconds(get_timestamp());
    
      if(now - to_seconds(last_updated.get(from_curr)) > 60|| 
         now - to_seconds(last_updated.get(to_curr)) > 60)
      update_exch_rate(curr_request);
    
      float exch_rate_from_curr = exch_rate.get(from_curr),
            exch_rate_to_curr   = exch_rate.get(to_curr);
    
      float result = (float) (amt) * (exch_rate_from_curr/exch_rate_to_curr);
      curr_request.update_result(result);
  }
  
  void update_exch_rate(RequestObject r) {
    char* from_curr = r.from(),
          to_curr   = r.to();
    
    float base_curr_from_curr, base_curr_to_curr; 
    
    if(from_curr != base_curr) 
      base_curr_from_curr = api.get_exchange_rate(base_cur, from_curr);
    
    if(to_curr != base_curr) 
      base_curr_to_curr = api.get_exchange_rate(base_cur, to_curr);
    
    // -1 
    /*
    {
      "ret_code": 400
      "desc": "No currency found"
    }
    */
    
    exch_rate.insert(pair<char*, float> (from_curr, base_curr_from_curr));
    exch_rate.insert(pair<char*, float> (to_curr, base_curr_to_curr));
    
    long now = get_timestamp();
    
    last_updated.insert(pair<char*, long> (from_curr, now()));
    last_updated.insert(pair<char*, long> (to_curr, now()));
  }
};
