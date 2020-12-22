import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-dept',
  templateUrl: './dept.component.html'
})
export class DeptComponent  {
  depts= [];
  constructor() 
  {
    this.depts = [
        {"DNo": 11, "DName": "IT1", "DCity": "Banglore1"},
        {"DNo": 12, "DName": "IT2", "DCity": "Banglore2"},
        {"DNo": 13, "DName": "IT3", "DCity": "Banglore3"}
    ];

   }
   DoSomething()
    {
  //    console.log("Hello");
//      this.depts.push({"DNo": 10, "DName": "admin", "DCity": "pune"});
      this.depts.splice(0,1);
    }

}
