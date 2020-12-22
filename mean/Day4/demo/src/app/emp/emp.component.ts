import { Component, OnInit } from '@angular/core';

// @Component({
//   selector: 'app-emp',
//   template: `<h1>{{No}}</h1>
//              <h3>{{Name}}</h3>
//              <h6>{{Address}}</h6>`
// })
@Component({
  selector: 'app-emp',
  template: `<input type="text" value="{{Name}}">`
})
export class EmpComponent {
  No: number;
  Name: string;
  Address: string;

  constructor() { 
    this.No = 1;
    this.Name = "Mahesh";
    this.Address = "Pune";
  }


}
