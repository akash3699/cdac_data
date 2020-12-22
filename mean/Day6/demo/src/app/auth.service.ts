import { Injectable } from '@angular/core';
import { CanActivate, ActivatedRouteSnapshot, RouterStateSnapshot, Router } from '@angular/router';

@Injectable({
  providedIn: 'root'
})
export class AuthService  implements CanActivate 
{
  constructor(public router:Router)
  {

  } 

  isLoggedIn()
  {
    return (sessionStorage.getItem("isloggedIn") == "1");
  }
  canActivate(route: ActivatedRouteSnapshot, state: RouterStateSnapshot)
  {
    if(this.isLoggedIn())
    {
      return true;
    }
    else
    {
      this.router.navigate(['login']);
      return false;    
    }
  }

  Login(credentials: any)
  {
    //Submit these credentials to server
    //check with db  instead of hard coded check
    //use http.post() & return observable collection
    //& let login component subscribe to this method

    if(credentials.name=="abc" && 
        credentials.password=="abc@123")
    {
      sessionStorage.setItem("isloggedIn", "1");
      return true;
    }
    else
    {
      return false;
    }
  }

  Logout(){
    sessionStorage.setItem("isloggedIn", "0");
    this.router.navigate(['login']);
  }

}




