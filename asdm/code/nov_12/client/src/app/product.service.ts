import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'

@Injectable({
  providedIn: 'root'
})
export class ProductService {

  url = 'http://3.86.24.77:4000/product'

  constructor(private http: HttpClient) { }

  get() {
    return this.http.get(this.url)
  }
}
