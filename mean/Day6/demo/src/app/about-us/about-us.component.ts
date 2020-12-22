import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-about-us',
  templateUrl: './about-us.component.html',
  styleUrls: ['./about-us.component.css']
})
export class AboutUsComponent implements OnInit {

  constructor() { }

  ngOnInit() 
  {
    console.log("About Us Component Loaded")
  }


  ngOnDestroy()
  {
    console.log("About Us Component Destroyed")
  }
}
