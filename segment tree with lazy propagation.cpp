// create
ll n; 
ll seg[4*n];
ll lazy[4*n];
ll vec[5]={};// input array
void create(ll ind,ll l,ll r){
	if(l==r){
		seg[ind]=vec[l];
		return;
	}
	
	create(ind*2,l,l+(r-l)/2);
	create(ind*2+1,l+(r-l)/2+1,r);
	
	seg[ind]=seg[ind*2]+seg[ind*2+1];// change
}


// query
ll query(ll ind,ll ql,ll qr,ll l,ll r){
	
	if(lazy[ind]!=0){// lazy propagation // change
		ll dx=lazy[ind];
		lazy[ind]=0;
		seg[ind]+=dx*(r-l+1);
		
		if(l!=r){
			lazy[2*ind]+=dx;
			lazy[2*ind+1]+=dx;
		}
	}
	
	
	if(r<ql or l>qr) return 0;// no overlap
	
	if(l>=ql and r<=qr) return seg[ind]; // completete overlap
	
	// partial overlap
	ll leftAns=query(2*ind,ql,qr,l,l+(r-l)/2);
	ll rightAns=query(2*ind+1,ql,qr,l+(r-l)/2+1,r);
	return leftAns+rightAns;
}

//update
void point_update(ll ind,ll upd_ind,ll upd_val,ll l,ll r){
	if(l==r and r==upd_ind) {seg[ind]+=upd_val;return;}// change how to update the point
	
	if(upd_ind>r or upd_ind<l) return;// no overlap
	
	update(ind*2,upd_ind,upd_val,l,l+(r-l)/2);
	update(ind*2+1,upd_ind,upd_val,l+(r-l)/2+1,r);
	
	seg[ind]=seg[ind*2]+seg[ind*2+1];// change
}

void range_update(ll ind,ll ul,ll ur,ll upd_val,ll l,ll r){
	
	if(lazy[ind]!=0){// lazy propagation // change
		ll dx=lazy[ind];
		lazy[ind]=0;
		seg[ind]+=dx*(r-l+1);
		
		if(l!=r){
			lazy[2*ind]+=dx;
			lazy[2*ind+1]+=dx;
		}
		return;
	}
	
	
	if(r<ul or l>ur) return;// no overlap
	
	if(l>=ul and r<=ur){ // completete overlap // change
		ll dx=(r-l+1)*upd_val;
		seg[ind]+=dx;
		
		if(l!=r){
			lazy[2*ind]+=upd_val;
			lazy[2*ind+1]+=upd_val;
		}
		return;
	}
	
	// partial overlap
	range_update(2*ind,ul,ur,upd_val,l,l+(r-l)/2);
	range_update(2*ind+1,ul,ur,upd_val,l+(r-l)/2+1,r);
	
	seg[ind]=seg[ind*2]+seg[ind*2+1];// change
}







