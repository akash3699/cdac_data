import { Component, OnInit } from '@angular/core';
import { ProductService } from '../product.service';

@Component({
  selector: 'app-product-list',
  templateUrl: './product-list.component.html',
  styleUrls: ['./product-list.component.css']
})
export class ProductListComponent implements OnInit {

  products = []

  constructor(private service: ProductService) { }

  ngOnInit() {
    this.service
      .get()
      .subscribe(response => {
        this.products = response as []
        console.log(this.products)
      })
  }

}
