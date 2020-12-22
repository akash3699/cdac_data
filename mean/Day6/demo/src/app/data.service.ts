import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class DataService {

  constructor(public http: HttpClient) { }

  GetData()
  {
   return this.http.get("http://localhost:4000/employees");
  }

  DeleteData(No)
  {
    return this.http.delete("http://localhost:4000/employees/" +No );
  }

  UpdateData(empObject)
  {
    console.log(empObject)
    return this.http.put("http://localhost:4000/employees/" + empObject.no,empObject );
  }

  GetDataByID(No)
  {
   return this.http.get("http://localhost:4000/employees/" +No );
  }

  AddData(empObject)
  {
   return this.http.post("http://localhost:4000/employees", empObject);
  }
}






